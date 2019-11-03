/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "GOST34310Sign.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/GOST34310Sign.c"

static asn_TYPE_member_t asn_MBR_GOST34310Sign_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct GOST34310Sign, r),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "r"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct GOST34310Sign, s),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "s"
    },
};
static const ber_tlv_tag_t GOST34310Sign_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GOST34310Sign_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* r */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, -1, 0 } /* s */
};
static asn_SEQUENCE_specifics_t asn_SPC_GOST34310Sign_specs_1 = {
    sizeof(struct GOST34310Sign),
    offsetof(struct GOST34310Sign, _asn_ctx),
    asn_MAP_GOST34310Sign_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t GOST34310Sign_desc = {
    "GOST34310Sign",
    "GOST34310Sign",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    GOST34310Sign_desc_tags_1,
    sizeof(GOST34310Sign_desc_tags_1)
    / sizeof(GOST34310Sign_desc_tags_1[0]), /* 1 */
    GOST34310Sign_desc_tags_1,    /* Same as above */
    sizeof(GOST34310Sign_desc_tags_1)
    / sizeof(GOST34310Sign_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_GOST34310Sign_1,
    2,    /* Elements count */
    &asn_SPC_GOST34310Sign_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_GOST34310Sign_desc(void)
{
    return &GOST34310Sign_desc;
}
