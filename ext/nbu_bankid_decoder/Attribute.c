/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "Attribute.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/Attribute.c"

static asn_TYPE_member_t asn_MBR_value_3[] = {
    {
        ATF_OPEN_TYPE | ATF_POINTER, 0, 0,
        -1 /* Ambiguous tag (ANY?) */,
        0,
        &AttributeValue_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t value_desc_tags_3[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_value_specs_3 = {
    sizeof(struct value),
    offsetof(struct value, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t value_3_desc = {
    "value",
    "value",
    SET_OF_free,
    SET_OF_print,
    SET_OF_constraint,
    SET_OF_decode_ber,
    SET_OF_encode_der,
    SET_OF_decode_xer,
    SET_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    value_desc_tags_3,
    sizeof(value_desc_tags_3)
    / sizeof(value_desc_tags_3[0]), /* 1 */
    value_desc_tags_3,    /* Same as above */
    sizeof(value_desc_tags_3)
    / sizeof(value_desc_tags_3[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_value_3,
    1,    /* Single element */
    &asn_SPC_value_specs_3    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Attribute_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct Attribute, type),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &OBJECT_IDENTIFIER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "type"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct Attribute, value),
        (ASN_TAG_CLASS_UNIVERSAL | (17 << 2)),
        0,
        &value_3_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "value"
    },
};
static const ber_tlv_tag_t Attribute_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Attribute_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* type */
    { (ASN_TAG_CLASS_UNIVERSAL | (17 << 2)), 1, 0, 0 } /* value */
};
static asn_SEQUENCE_specifics_t asn_SPC_Attribute_specs_1 = {
    sizeof(struct Attribute),
    offsetof(struct Attribute, _asn_ctx),
    asn_MAP_Attribute_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t Attribute_desc = {
    "Attribute",
    "Attribute",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    Attribute_desc_tags_1,
    sizeof(Attribute_desc_tags_1)
    / sizeof(Attribute_desc_tags_1[0]), /* 1 */
    Attribute_desc_tags_1,    /* Same as above */
    sizeof(Attribute_desc_tags_1)
    / sizeof(Attribute_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_Attribute_1,
    2,    /* Elements count */
    &asn_SPC_Attribute_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_Attribute_desc(void)
{
    return &Attribute_desc;
}
