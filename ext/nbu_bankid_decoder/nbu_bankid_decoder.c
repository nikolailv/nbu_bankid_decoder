#include <stdio.h>
#include <stdlib.h>
#include "byte_array.h"
#include "gost28147.h"
#include <ruby.h>

static ByteArray* gost28147_ctr_core(uint8_t *enc_data, size_t data_size, uint8_t *key, size_t key_size, uint8_t * iv, size_t iv_size)
{
    Gost28147Ctx *ctx = NULL;
    ByteArray *encoded = NULL;
    ByteArray *decoded = NULL;
    ByteArray *key_ba = NULL;
    ByteArray *data_ba = NULL;
    ByteArray *iv_ba = NULL;

    data_ba = ba_alloc_from_uint8(enc_data, data_size);
    key_ba = ba_alloc_from_uint8(key, key_size);
    iv_ba = ba_alloc_from_uint8(iv, iv_size);

    ctx = gost28147_alloc(GOST28147_SBOX_ID_1);
    gost28147_init_ctr(ctx, key_ba, iv_ba);
    gost28147_decrypt(ctx, data_ba, &decoded);

cleanup:
    ba_free(data_ba);
    ba_free(key_ba);
    ba_free(iv_ba);
    gost28147_free(ctx);
    return decoded;
}

VALUE gost28147_ctr_decode(VALUE self, VALUE data, VALUE key, VALUE iv) {
    ByteArray * decoded;
    VALUE str_out;
    decoded = gost28147_ctr_core(
        (uint8_t*)RSTRING_PTR(data), RSTRING_LEN(data),
        (uint8_t*)RSTRING_PTR(key), RSTRING_LEN(key),
        (uint8_t*)RSTRING_PTR(iv), RSTRING_LEN(iv));

    str_out = rb_str_new(ba->buf, ba->len);
    ba_free(decoded);
    return str_out;
}

void Init_nby_bankid_decoder(void) {
  VALUE mNbuBankIdDecoder = rb_define_module("NbuBankIdDecoder");
  rb_define_singleton_method(mNbuBankIdDecoder, "gost28147_ctr_decode", 3)
}
