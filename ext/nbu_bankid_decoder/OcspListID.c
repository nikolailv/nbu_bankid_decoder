/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "OcspListID.h"

#include "asn_internal.h"

#include "OcspResponsesID.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/OcspListID.c"

static asn_TYPE_member_t asn_MBR_ocspResponses_2[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &OcspResponsesID_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t ocspResponses_desc_tags_2[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ocspResponses_specs_2 = {
    sizeof(struct ocspResponses),
    offsetof(struct ocspResponses, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t ocspResponses_2_desc = {
    "ocspResponses",
    "ocspResponses",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ocspResponses_desc_tags_2,
    sizeof(ocspResponses_desc_tags_2)
    / sizeof(ocspResponses_desc_tags_2[0]), /* 1 */
    ocspResponses_desc_tags_2,    /* Same as above */
    sizeof(ocspResponses_desc_tags_2)
    / sizeof(ocspResponses_desc_tags_2[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ocspResponses_2,
    1,    /* Single element */
    &asn_SPC_ocspResponses_specs_2    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_OcspListID_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct OcspListID, ocspResponses),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &ocspResponses_2_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "ocspResponses"
    },
};
static const ber_tlv_tag_t OcspListID_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_OcspListID_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 0 } /* ocspResponses */
};
static asn_SEQUENCE_specifics_t asn_SPC_OcspListID_specs_1 = {
    sizeof(struct OcspListID),
    offsetof(struct OcspListID, _asn_ctx),
    asn_MAP_OcspListID_tag2el_1,
    1,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t OcspListID_desc = {
    "OcspListID",
    "OcspListID",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    OcspListID_desc_tags_1,
    sizeof(OcspListID_desc_tags_1)
    / sizeof(OcspListID_desc_tags_1[0]), /* 1 */
    OcspListID_desc_tags_1,    /* Same as above */
    sizeof(OcspListID_desc_tags_1)
    / sizeof(OcspListID_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_OcspListID_1,
    1,    /* Elements count */
    &asn_SPC_OcspListID_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_OcspListID_desc(void)
{
    return &OcspListID_desc;
}
