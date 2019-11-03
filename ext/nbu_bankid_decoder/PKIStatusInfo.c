/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "PKIStatusInfo.h"

#include "asn_internal.h"

#include "PKIFreeText.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/PKIStatusInfo.c"

static asn_TYPE_member_t asn_MBR_PKIStatusInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct PKIStatusInfo, status),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &PKIStatus_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "status"
    },
    {
        ATF_POINTER, 2, offsetof(struct PKIStatusInfo, statusString),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &PKIFreeText_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "statusString"
    },
    {
        ATF_POINTER, 1, offsetof(struct PKIStatusInfo, failInfo),
        (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
        0,
        &PKIFailureInfo_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "failInfo"
    },
};
static const ber_tlv_tag_t PKIStatusInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PKIStatusInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* status */
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 2, 0, 0 }, /* failInfo */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* statusString */
};
static asn_SEQUENCE_specifics_t asn_SPC_PKIStatusInfo_specs_1 = {
    sizeof(struct PKIStatusInfo),
    offsetof(struct PKIStatusInfo, _asn_ctx),
    asn_MAP_PKIStatusInfo_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t PKIStatusInfo_desc = {
    "PKIStatusInfo",
    "PKIStatusInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    PKIStatusInfo_desc_tags_1,
    sizeof(PKIStatusInfo_desc_tags_1)
    / sizeof(PKIStatusInfo_desc_tags_1[0]), /* 1 */
    PKIStatusInfo_desc_tags_1,    /* Same as above */
    sizeof(PKIStatusInfo_desc_tags_1)
    / sizeof(PKIStatusInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_PKIStatusInfo_1,
    3,    /* Elements count */
    &asn_SPC_PKIStatusInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_PKIStatusInfo_desc(void)
{
    return &PKIStatusInfo_desc;
}
