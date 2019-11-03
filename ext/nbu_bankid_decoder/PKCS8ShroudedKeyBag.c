/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "PKCS8ShroudedKeyBag.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/PKCS8ShroudedKeyBag.c"

int
PKCS8ShroudedKeyBag_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = EncryptedPrivateKeyInfo_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using EncryptedPrivateKeyInfo,
 * so here we adjust the DEF accordingly.
 */
static void
PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = EncryptedPrivateKeyInfo_desc.free_struct;
    td->print_struct   = EncryptedPrivateKeyInfo_desc.print_struct;
    td->check_constraints = EncryptedPrivateKeyInfo_desc.check_constraints;
    td->ber_decoder    = EncryptedPrivateKeyInfo_desc.ber_decoder;
    td->der_encoder    = EncryptedPrivateKeyInfo_desc.der_encoder;
    td->xer_decoder    = EncryptedPrivateKeyInfo_desc.xer_decoder;
    td->xer_encoder    = EncryptedPrivateKeyInfo_desc.xer_encoder;
    td->uper_decoder   = EncryptedPrivateKeyInfo_desc.uper_decoder;
    td->uper_encoder   = EncryptedPrivateKeyInfo_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = EncryptedPrivateKeyInfo_desc.per_constraints;
    }
    td->elements       = EncryptedPrivateKeyInfo_desc.elements;
    td->elements_count = EncryptedPrivateKeyInfo_desc.elements_count;
    td->specifics      = EncryptedPrivateKeyInfo_desc.specifics;
}

void
PKCS8ShroudedKeyBag_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
PKCS8ShroudedKeyBag_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
PKCS8ShroudedKeyBag_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
PKCS8ShroudedKeyBag_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
PKCS8ShroudedKeyBag_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
PKCS8ShroudedKeyBag_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    PKCS8ShroudedKeyBag_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t PKCS8ShroudedKeyBag_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t PKCS8ShroudedKeyBag_desc = {
    "PKCS8ShroudedKeyBag",
    "PKCS8ShroudedKeyBag",
    PKCS8ShroudedKeyBag_free,
    PKCS8ShroudedKeyBag_print,
    PKCS8ShroudedKeyBag_constraint,
    PKCS8ShroudedKeyBag_decode_ber,
    PKCS8ShroudedKeyBag_encode_der,
    PKCS8ShroudedKeyBag_decode_xer,
    PKCS8ShroudedKeyBag_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    PKCS8ShroudedKeyBag_desc_tags_1,
    sizeof(PKCS8ShroudedKeyBag_desc_tags_1)
    / sizeof(PKCS8ShroudedKeyBag_desc_tags_1[0]), /* 1 */
    PKCS8ShroudedKeyBag_desc_tags_1,    /* Same as above */
    sizeof(PKCS8ShroudedKeyBag_desc_tags_1)
    / sizeof(PKCS8ShroudedKeyBag_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_PKCS8ShroudedKeyBag_desc(void)
{
    return &PKCS8ShroudedKeyBag_desc;
}
