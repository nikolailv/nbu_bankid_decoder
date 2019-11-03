#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>
#include "byte_array.h"
#include "byte_array_internal.h"
#include "gost28147.h"
#include "cert.h"
#include "asn1_utils.h"
#include "cryptonite_manager.h"
#include "content_info.h"
#include "pkcs8.h"

static ByteArray* gost28147_ctr_core(uint8_t *enc_data, size_t data_size, uint8_t *key, size_t key_size, uint8_t * iv, size_t iv_size)
{
    Gost28147Ctx *ctx = NULL;
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

    str_out = rb_str_new((char*)decoded->buf, decoded->len);
    ba_free(decoded);
    return str_out;
}

VALUE decrypt_envelope_main(VALUE self, VALUE private_key, VALUE public_cert, VALUE bank_cert, VALUE envelope)
{
    ByteArray * my_cert_encoded = NULL;
    Certificate_t *subject_cert = NULL;

    ByteArray * bank_cert_encoded = NULL;
    Certificate_t *issuer_cert = NULL;

    ByteArray * key_encoded = NULL;
    PrivateKeyInfo_t * privkey = NULL;
    DhAdapter * subject_dha = NULL;

    ByteArray * env_bytes = NULL;
    ContentInfo_t *enveloped_data = NULL;

    ByteArray *decrypted_data = NULL;
    EnvelopedData_t *ed = NULL;

    VALUE str_out;

    // Load our public certificate
    my_cert_encoded = ba_alloc_from_uint8((uint8_t*)RSTRING_PTR(public_cert), RSTRING_LEN(public_cert));
    subject_cert = cert_alloc();
    cert_decode(subject_cert, my_cert_encoded);
    ba_free(my_cert_encoded);

    // Load public certificate from bank
    bank_cert_encoded = ba_alloc_from_uint8((uint8_t*)RSTRING_PTR(bank_cert), RSTRING_LEN(bank_cert));
    issuer_cert = cert_alloc();
    cert_decode(issuer_cert, bank_cert_encoded);
    ba_free(bank_cert_encoded);

    // Load our private key, init DH
    key_encoded = ba_alloc_from_uint8((uint8_t*)RSTRING_PTR(private_key), RSTRING_LEN(private_key));
    privkey = asn_decode_ba_with_alloc(&PrivateKeyInfo_desc, key_encoded);
    pkcs8_get_dh_adapter(privkey, &subject_dha);
    ba_free(key_encoded);

    // Load envelope
    env_bytes = ba_alloc_from_uint8((uint8_t*)RSTRING_PTR(envelope), RSTRING_LEN(envelope));
    enveloped_data = cinfo_alloc();
    asn_decode_ba(&ContentInfo_desc, enveloped_data, env_bytes);
    ba_free(env_bytes);
    cinfo_get_enveloped_data(enveloped_data, &ed);

    // DECRYPT
    env_decrypt_data(ed, NULL, issuer_cert, subject_dha, subject_cert, &decrypted_data);

    // cleanup
    env_data_free(ed);
    cert_free(issuer_cert);
    cert_free(subject_cert);
    cinfo_free(enveloped_data);
    dh_adapter_free(subject_dha);

    // return
    if (decrypted_data) {
        str_out = rb_str_new((char*)decrypted_data->buf, decrypted_data->len);
        ba_free(decrypted_data);
        return str_out;
    } else {
        return Qnil;
    }
}

void Init_nbu_bankid_decoder(void) {
  VALUE mNbuBankIdDecoder = rb_define_module("NbuBankIdDecoder");
  rb_define_singleton_method(mNbuBankIdDecoder, "gost28147_ctr_decode", gost28147_ctr_decode, 3);
  rb_define_singleton_method(mNbuBankIdDecoder, "decrypt_envelope", decrypt_envelope_main, 4);
}
