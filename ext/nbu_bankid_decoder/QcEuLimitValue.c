/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "QcEuLimitValue.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/QcEuLimitValue.c"

int
QcEuLimitValue_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = MonetaryValue_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using MonetaryValue,
 * so here we adjust the DEF accordingly.
 */
static void
QcEuLimitValue_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = MonetaryValue_desc.free_struct;
    td->print_struct   = MonetaryValue_desc.print_struct;
    td->check_constraints = MonetaryValue_desc.check_constraints;
    td->ber_decoder    = MonetaryValue_desc.ber_decoder;
    td->der_encoder    = MonetaryValue_desc.der_encoder;
    td->xer_decoder    = MonetaryValue_desc.xer_decoder;
    td->xer_encoder    = MonetaryValue_desc.xer_encoder;
    td->uper_decoder   = MonetaryValue_desc.uper_decoder;
    td->uper_encoder   = MonetaryValue_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = MonetaryValue_desc.per_constraints;
    }
    td->elements       = MonetaryValue_desc.elements;
    td->elements_count = MonetaryValue_desc.elements_count;
    td->specifics      = MonetaryValue_desc.specifics;
}

void
QcEuLimitValue_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    QcEuLimitValue_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
QcEuLimitValue_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    QcEuLimitValue_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
QcEuLimitValue_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    QcEuLimitValue_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
QcEuLimitValue_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    QcEuLimitValue_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
QcEuLimitValue_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    QcEuLimitValue_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
QcEuLimitValue_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    QcEuLimitValue_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t QcEuLimitValue_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t QcEuLimitValue_desc = {
    "QcEuLimitValue",
    "QcEuLimitValue",
    QcEuLimitValue_free,
    QcEuLimitValue_print,
    QcEuLimitValue_constraint,
    QcEuLimitValue_decode_ber,
    QcEuLimitValue_encode_der,
    QcEuLimitValue_decode_xer,
    QcEuLimitValue_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    QcEuLimitValue_desc_tags_1,
    sizeof(QcEuLimitValue_desc_tags_1)
    / sizeof(QcEuLimitValue_desc_tags_1[0]), /* 1 */
    QcEuLimitValue_desc_tags_1,    /* Same as above */
    sizeof(QcEuLimitValue_desc_tags_1)
    / sizeof(QcEuLimitValue_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_QcEuLimitValue_desc(void)
{
    return &QcEuLimitValue_desc;
}
