/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "NoticeReference.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/NoticeReference.c"

static asn_TYPE_member_t asn_MBR_noticeNumbers_3[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t noticeNumbers_desc_tags_3[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_noticeNumbers_specs_3 = {
    sizeof(struct noticeNumbers),
    offsetof(struct noticeNumbers, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t noticeNumbers_3_desc = {
    "noticeNumbers",
    "noticeNumbers",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    noticeNumbers_desc_tags_3,
    sizeof(noticeNumbers_desc_tags_3)
    / sizeof(noticeNumbers_desc_tags_3[0]), /* 1 */
    noticeNumbers_desc_tags_3,    /* Same as above */
    sizeof(noticeNumbers_desc_tags_3)
    / sizeof(noticeNumbers_desc_tags_3[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_noticeNumbers_3,
    1,    /* Single element */
    &asn_SPC_noticeNumbers_specs_3    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_NoticeReference_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct NoticeReference, organization),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &DisplayText_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "organization"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct NoticeReference, noticeNumbers),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &noticeNumbers_3_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "noticeNumbers"
    },
};
static const ber_tlv_tag_t NoticeReference_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NoticeReference_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (12 << 2)), 0, 0, 0 }, /* utf8String */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 }, /* noticeNumbers */
    { (ASN_TAG_CLASS_UNIVERSAL | (26 << 2)), 0, 0, 0 }, /* visibleString */
    { (ASN_TAG_CLASS_UNIVERSAL | (30 << 2)), 0, 0, 0 } /* bmpString */
};
static asn_SEQUENCE_specifics_t asn_SPC_NoticeReference_specs_1 = {
    sizeof(struct NoticeReference),
    offsetof(struct NoticeReference, _asn_ctx),
    asn_MAP_NoticeReference_tag2el_1,
    4,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t NoticeReference_desc = {
    "NoticeReference",
    "NoticeReference",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    NoticeReference_desc_tags_1,
    sizeof(NoticeReference_desc_tags_1)
    / sizeof(NoticeReference_desc_tags_1[0]), /* 1 */
    NoticeReference_desc_tags_1,    /* Same as above */
    sizeof(NoticeReference_desc_tags_1)
    / sizeof(NoticeReference_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_NoticeReference_1,
    2,    /* Elements count */
    &asn_SPC_NoticeReference_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_NoticeReference_desc(void)
{
    return &NoticeReference_desc;
}
