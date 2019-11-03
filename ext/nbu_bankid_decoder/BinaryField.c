/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "BinaryField.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/BinaryField.c"

static asn_TYPE_member_t asn_MBR_member_3[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct member, choice.trinomial),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "trinomial"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct member, choice.pentanomial),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &Pentanomial_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "pentanomial"
    },
};
static const asn_TYPE_tag2member_t asn_MAP_member_tag2el_3[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* trinomial */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* pentanomial */
};
static asn_CHOICE_specifics_t asn_SPC_member_specs_3 = {
    sizeof(struct member),
    offsetof(struct member, _asn_ctx),
    offsetof(struct member, present),
    sizeof(((struct member *)0)->present),
    asn_MAP_member_tag2el_3,
    2,    /* Count of tags in the map */
    0,
    -1    /* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t member_3_desc = {
    "member",
    "member",
    CHOICE_free,
    CHOICE_print,
    CHOICE_constraint,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    CHOICE_outmost_tag,
    0,    /* No effective tags (pointer) */
    0,    /* No effective tags (count) */
    0,    /* No tags (pointer) */
    0,    /* No tags (count) */
    0,    /* No PER visible constraints */
    asn_MBR_member_3,
    2,    /* Elements count */
    &asn_SPC_member_specs_3    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_BinaryField_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct BinaryField, m),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "m"
    },
    {
        ATF_POINTER, 1, offsetof(struct BinaryField, member),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &member_3_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "member"
    },
};
static const ber_tlv_tag_t BinaryField_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_BinaryField_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* m */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, -1, 0 }, /* trinomial */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* pentanomial */
};
static asn_SEQUENCE_specifics_t asn_SPC_BinaryField_specs_1 = {
    sizeof(struct BinaryField),
    offsetof(struct BinaryField, _asn_ctx),
    asn_MAP_BinaryField_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t BinaryField_desc = {
    "BinaryField",
    "BinaryField",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    BinaryField_desc_tags_1,
    sizeof(BinaryField_desc_tags_1)
    / sizeof(BinaryField_desc_tags_1[0]), /* 1 */
    BinaryField_desc_tags_1,    /* Same as above */
    sizeof(BinaryField_desc_tags_1)
    / sizeof(BinaryField_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_BinaryField_1,
    2,    /* Elements count */
    &asn_SPC_BinaryField_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_BinaryField_desc(void)
{
    return &BinaryField_desc;
}
