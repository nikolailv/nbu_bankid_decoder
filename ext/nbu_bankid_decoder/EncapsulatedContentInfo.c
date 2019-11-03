/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "EncapsulatedContentInfo.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/EncapsulatedContentInfo.c"

static asn_TYPE_member_t asn_MBR_EncapsulatedContentInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct EncapsulatedContentInfo, eContentType),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &ContentType_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "eContentType"
    },
    {
        ATF_POINTER, 1, offsetof(struct EncapsulatedContentInfo, eContent),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &OCTET_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "eContent"
    },
};
static const ber_tlv_tag_t EncapsulatedContentInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_EncapsulatedContentInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* eContentType */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 1, 0, 0 } /* eContent */
};
static asn_SEQUENCE_specifics_t asn_SPC_EncapsulatedContentInfo_specs_1 = {
    sizeof(struct EncapsulatedContentInfo),
    offsetof(struct EncapsulatedContentInfo, _asn_ctx),
    asn_MAP_EncapsulatedContentInfo_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t EncapsulatedContentInfo_desc = {
    "EncapsulatedContentInfo",
    "EncapsulatedContentInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    EncapsulatedContentInfo_desc_tags_1,
    sizeof(EncapsulatedContentInfo_desc_tags_1)
    / sizeof(EncapsulatedContentInfo_desc_tags_1[0]), /* 1 */
    EncapsulatedContentInfo_desc_tags_1,    /* Same as above */
    sizeof(EncapsulatedContentInfo_desc_tags_1)
    / sizeof(EncapsulatedContentInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_EncapsulatedContentInfo_1,
    2,    /* Elements count */
    &asn_SPC_EncapsulatedContentInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_EncapsulatedContentInfo_desc(void)
{
    return &EncapsulatedContentInfo_desc;
}
