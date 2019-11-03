/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "CRLReason.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/CRLReason.c"

int
CRLReason_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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
CRLReason_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
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
CRLReason_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    CRLReason_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
CRLReason_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    CRLReason_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
CRLReason_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    CRLReason_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
CRLReason_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    CRLReason_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
CRLReason_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    CRLReason_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
CRLReason_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    CRLReason_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const asn_INTEGER_enum_map_t asn_MAP_CRLReason_value2enum_1[] = {
    { 0,    11,    "unspecified" },
    { 1,    13,    "keyCompromise" },
    { 2,    12,    "cACompromise" },
    { 3,    18,    "affiliationChanged" },
    { 4,    10,    "superseded" },
    { 5,    20,    "cessationOfOperation" },
    { 6,    15,    "certificateHold" },
    { 8,    13,    "removeFromCRL" },
    { 9,    18,    "privilegeWithdrawn" },
    { 10,    12,    "aACompromise" }
};
static const unsigned int asn_MAP_CRLReason_enum2value_1[] = {
    9,    /* aACompromise(10) */
    3,    /* affiliationChanged(3) */
    2,    /* cACompromise(2) */
    6,    /* certificateHold(6) */
    5,    /* cessationOfOperation(5) */
    1,    /* keyCompromise(1) */
    8,    /* privilegeWithdrawn(9) */
    7,    /* removeFromCRL(8) */
    4,    /* superseded(4) */
    0    /* unspecified(0) */
};
static asn_INTEGER_specifics_t asn_SPC_CRLReason_specs_1 = {
    asn_MAP_CRLReason_value2enum_1,    /* "tag" => N; sorted by tag */
    asn_MAP_CRLReason_enum2value_1,    /* N => "tag"; sorted by N */
    10,    /* Number of elements in the maps */
    0,    /* Enumeration is not extensible */
    1,    /* Strict enumeration */
    0,    /* Native long size */
    0
};
static const ber_tlv_tag_t CRLReason_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t CRLReason_desc = {
    "CRLReason",
    "CRLReason",
    CRLReason_free,
    CRLReason_print,
    CRLReason_constraint,
    CRLReason_decode_ber,
    CRLReason_encode_der,
    CRLReason_decode_xer,
    CRLReason_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    CRLReason_desc_tags_1,
    sizeof(CRLReason_desc_tags_1)
    / sizeof(CRLReason_desc_tags_1[0]), /* 1 */
    CRLReason_desc_tags_1,    /* Same as above */
    sizeof(CRLReason_desc_tags_1)
    / sizeof(CRLReason_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    &asn_SPC_CRLReason_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_CRLReason_desc(void)
{
    return &CRLReason_desc;
}
