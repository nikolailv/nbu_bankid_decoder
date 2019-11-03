/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "ECDSA-Sig-Value.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/ECDSA-Sig-Value.c"

static asn_TYPE_member_t asn_MBR_ECDSA_Sig_Value_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct ECDSA_Sig_Value, r),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "r"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ECDSA_Sig_Value, s),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "s"
    },
};
static const ber_tlv_tag_t ECDSA_Sig_Value_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ECDSA_Sig_Value_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* r */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, -1, 0 } /* s */
};
static asn_SEQUENCE_specifics_t asn_SPC_ECDSA_Sig_Value_specs_1 = {
    sizeof(struct ECDSA_Sig_Value),
    offsetof(struct ECDSA_Sig_Value, _asn_ctx),
    asn_MAP_ECDSA_Sig_Value_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t ECDSA_Sig_Value_desc = {
    "ECDSA-Sig-Value",
    "ECDSA-Sig-Value",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ECDSA_Sig_Value_desc_tags_1,
    sizeof(ECDSA_Sig_Value_desc_tags_1)
    / sizeof(ECDSA_Sig_Value_desc_tags_1[0]), /* 1 */
    ECDSA_Sig_Value_desc_tags_1,    /* Same as above */
    sizeof(ECDSA_Sig_Value_desc_tags_1)
    / sizeof(ECDSA_Sig_Value_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ECDSA_Sig_Value_1,
    2,    /* Elements count */
    &asn_SPC_ECDSA_Sig_Value_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_ECDSA_Sig_Value_desc(void)
{
    return &ECDSA_Sig_Value_desc;
}
