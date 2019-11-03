/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "DistributionPoint.h"

#include "asn_internal.h"

#include "DistributionPointName.h"
#include "GeneralNames.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/DistributionPoint.c"

static asn_TYPE_member_t asn_MBR_DistributionPoint_1[] = {
    {
        ATF_POINTER, 3, offsetof(struct DistributionPoint, distributionPoint),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &DistributionPointName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "distributionPoint"
    },
    {
        ATF_POINTER, 2, offsetof(struct DistributionPoint, reasons),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &ReasonFlags_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "reasons"
    },
    {
        ATF_POINTER, 1, offsetof(struct DistributionPoint, crlIssuer),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &GeneralNames_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "crlIssuer"
    },
};
static const ber_tlv_tag_t DistributionPoint_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DistributionPoint_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* distributionPoint */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* reasons */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* crlIssuer */
};
static asn_SEQUENCE_specifics_t asn_SPC_DistributionPoint_specs_1 = {
    sizeof(struct DistributionPoint),
    offsetof(struct DistributionPoint, _asn_ctx),
    asn_MAP_DistributionPoint_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t DistributionPoint_desc = {
    "DistributionPoint",
    "DistributionPoint",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    DistributionPoint_desc_tags_1,
    sizeof(DistributionPoint_desc_tags_1)
    / sizeof(DistributionPoint_desc_tags_1[0]), /* 1 */
    DistributionPoint_desc_tags_1,    /* Same as above */
    sizeof(DistributionPoint_desc_tags_1)
    / sizeof(DistributionPoint_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_DistributionPoint_1,
    3,    /* Elements count */
    &asn_SPC_DistributionPoint_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_DistributionPoint_desc(void)
{
    return &DistributionPoint_desc;
}
