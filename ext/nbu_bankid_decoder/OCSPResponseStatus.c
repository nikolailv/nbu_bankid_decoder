/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "OCSPResponseStatus.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/OCSPResponseStatus.c"

int
OCSPResponseStatus_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = ENUMERATED_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ENUMERATED,
 * so here we adjust the DEF accordingly.
 */
static void
OCSPResponseStatus_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = ENUMERATED_desc.free_struct;
    td->print_struct   = ENUMERATED_desc.print_struct;
    td->check_constraints = ENUMERATED_desc.check_constraints;
    td->ber_decoder    = ENUMERATED_desc.ber_decoder;
    td->der_encoder    = ENUMERATED_desc.der_encoder;
    td->xer_decoder    = ENUMERATED_desc.xer_decoder;
    td->xer_encoder    = ENUMERATED_desc.xer_encoder;
    td->uper_decoder   = ENUMERATED_desc.uper_decoder;
    td->uper_encoder   = ENUMERATED_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = ENUMERATED_desc.per_constraints;
    }
    td->elements       = ENUMERATED_desc.elements;
    td->elements_count = ENUMERATED_desc.elements_count;
    /* td->specifics      = ENUMERATED_desc.specifics;    // Defined explicitly */
}

void
OCSPResponseStatus_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    OCSPResponseStatus_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
OCSPResponseStatus_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    OCSPResponseStatus_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
OCSPResponseStatus_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    OCSPResponseStatus_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
OCSPResponseStatus_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    OCSPResponseStatus_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
OCSPResponseStatus_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    OCSPResponseStatus_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
OCSPResponseStatus_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    OCSPResponseStatus_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const asn_INTEGER_enum_map_t asn_MAP_OCSPResponseStatus_value2enum_1[] = {
    { 0,    10,    "successful" },
    { 1,    16,    "malformedRequest" },
    { 2,    13,    "internalError" },
    { 3,    8,    "tryLater" },
    { 5,    11,    "sigRequired" },
    { 6,    12,    "unauthorized" }
};
static const unsigned int asn_MAP_OCSPResponseStatus_enum2value_1[] = {
    2,    /* internalError(2) */
    1,    /* malformedRequest(1) */
    4,    /* sigRequired(5) */
    0,    /* successful(0) */
    3,    /* tryLater(3) */
    5    /* unauthorized(6) */
};
static asn_INTEGER_specifics_t asn_SPC_OCSPResponseStatus_specs_1 = {
    asn_MAP_OCSPResponseStatus_value2enum_1,    /* "tag" => N; sorted by tag */
    asn_MAP_OCSPResponseStatus_enum2value_1,    /* N => "tag"; sorted by N */
    6,    /* Number of elements in the maps */
    0,    /* Enumeration is not extensible */
    1,    /* Strict enumeration */
    0,    /* Native long size */
    0
};
static const ber_tlv_tag_t OCSPResponseStatus_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t OCSPResponseStatus_desc = {
    "OCSPResponseStatus",
    "OCSPResponseStatus",
    OCSPResponseStatus_free,
    OCSPResponseStatus_print,
    OCSPResponseStatus_constraint,
    OCSPResponseStatus_decode_ber,
    OCSPResponseStatus_encode_der,
    OCSPResponseStatus_decode_xer,
    OCSPResponseStatus_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    OCSPResponseStatus_desc_tags_1,
    sizeof(OCSPResponseStatus_desc_tags_1)
    / sizeof(OCSPResponseStatus_desc_tags_1[0]), /* 1 */
    OCSPResponseStatus_desc_tags_1,    /* Same as above */
    sizeof(OCSPResponseStatus_desc_tags_1)
    / sizeof(OCSPResponseStatus_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    &asn_SPC_OCSPResponseStatus_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_OCSPResponseStatus_desc(void)
{
    return &OCSPResponseStatus_desc;
}
