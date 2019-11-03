/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "TBSRequest.h"

#include "asn_internal.h"

#include "GeneralName.h"
#include "Extensions.h"
#include "Request.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/TBSRequest.c"

static int asn_DFL_2_set_0(int set_value, void **sptr)
{
    Version_t *st = *sptr;

    if (!st) {
        if (!set_value) {
            return -1;    /* Not a default value */
        }
        st = (*sptr = CALLOC(1, sizeof(*st)));
        if (!st) {
            return -1;
        }
    }

    if (set_value) {
        /* Install default value 0 */
        return asn_long2INTEGER(st, 0);
    } else {
        /* Test default value 0 */
        long value;
        if (asn_INTEGER2long(st, &value)) {
            return -1;
        }
        return (value == 0);
    }
}
static asn_TYPE_member_t asn_MBR_requestList_4[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &Request_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t requestList_desc_tags_4[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_requestList_specs_4 = {
    sizeof(struct requestList),
    offsetof(struct requestList, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t requestList_4_desc = {
    "requestList",
    "requestList",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    requestList_desc_tags_4,
    sizeof(requestList_desc_tags_4)
    / sizeof(requestList_desc_tags_4[0]), /* 1 */
    requestList_desc_tags_4,    /* Same as above */
    sizeof(requestList_desc_tags_4)
    / sizeof(requestList_desc_tags_4[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_requestList_4,
    1,    /* Single element */
    &asn_SPC_requestList_specs_4    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_TBSRequest_1[] = {
    {
        ATF_POINTER, 2, offsetof(struct TBSRequest, version),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &Version_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        asn_DFL_2_set_0,    /* DEFAULT 0 */
        "version"
    },
    {
        ATF_POINTER, 1, offsetof(struct TBSRequest, requestorName),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &GeneralName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "requestorName"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct TBSRequest, requestList),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &requestList_4_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "requestList"
    },
    {
        ATF_POINTER, 1, offsetof(struct TBSRequest, requestExtensions),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &Extensions_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "requestExtensions"
    },
};
static const ber_tlv_tag_t TBSRequest_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TBSRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 }, /* requestList */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* requestorName */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 3, 0, 0 } /* requestExtensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_TBSRequest_specs_1 = {
    sizeof(struct TBSRequest),
    offsetof(struct TBSRequest, _asn_ctx),
    asn_MAP_TBSRequest_tag2el_1,
    4,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t TBSRequest_desc = {
    "TBSRequest",
    "TBSRequest",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    TBSRequest_desc_tags_1,
    sizeof(TBSRequest_desc_tags_1)
    / sizeof(TBSRequest_desc_tags_1[0]), /* 1 */
    TBSRequest_desc_tags_1,    /* Same as above */
    sizeof(TBSRequest_desc_tags_1)
    / sizeof(TBSRequest_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_TBSRequest_1,
    4,    /* Elements count */
    &asn_SPC_TBSRequest_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_TBSRequest_desc(void)
{
    return &TBSRequest_desc;
}
