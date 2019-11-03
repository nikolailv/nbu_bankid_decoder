/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "OtherRecipientInfo.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/OtherRecipientInfo.c"

static asn_TYPE_member_t asn_MBR_OtherRecipientInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct OtherRecipientInfo, oriType),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &OBJECT_IDENTIFIER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "oriType"
    },
    {
        ATF_OPEN_TYPE | ATF_NOFLAGS, 0, offsetof(struct OtherRecipientInfo, oriValue),
        -1 /* Ambiguous tag (ANY?) */,
        0,
        &ANY_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "oriValue"
    },
};
static const ber_tlv_tag_t OtherRecipientInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_OtherRecipientInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 } /* oriType */
};
static asn_SEQUENCE_specifics_t asn_SPC_OtherRecipientInfo_specs_1 = {
    sizeof(struct OtherRecipientInfo),
    offsetof(struct OtherRecipientInfo, _asn_ctx),
    asn_MAP_OtherRecipientInfo_tag2el_1,
    1,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t OtherRecipientInfo_desc = {
    "OtherRecipientInfo",
    "OtherRecipientInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    OtherRecipientInfo_desc_tags_1,
    sizeof(OtherRecipientInfo_desc_tags_1)
    / sizeof(OtherRecipientInfo_desc_tags_1[0]), /* 1 */
    OtherRecipientInfo_desc_tags_1,    /* Same as above */
    sizeof(OtherRecipientInfo_desc_tags_1)
    / sizeof(OtherRecipientInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_OtherRecipientInfo_1,
    2,    /* Elements count */
    &asn_SPC_OtherRecipientInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_OtherRecipientInfo_desc(void)
{
    return &OtherRecipientInfo_desc;
}
