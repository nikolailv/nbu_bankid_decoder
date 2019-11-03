/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "ResponseData.h"

#include "asn_internal.h"

#include "Extensions.h"
#include "SingleResponse.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/ResponseData.c"

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
static asn_TYPE_member_t asn_MBR_responses_5[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &SingleResponse_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t responses_desc_tags_5[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_responses_specs_5 = {
    sizeof(struct responses),
    offsetof(struct responses, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t responses_5_desc = {
    "responses",
    "responses",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    responses_desc_tags_5,
    sizeof(responses_desc_tags_5)
    / sizeof(responses_desc_tags_5[0]), /* 1 */
    responses_desc_tags_5,    /* Same as above */
    sizeof(responses_desc_tags_5)
    / sizeof(responses_desc_tags_5[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_responses_5,
    1,    /* Single element */
    &asn_SPC_responses_specs_5    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ResponseData_1[] = {
    {
        ATF_POINTER, 1, offsetof(struct ResponseData, version),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &Version_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        asn_DFL_2_set_0,    /* DEFAULT 0 */
        "version"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ResponseData, responderID),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &ResponderID_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "responderID"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ResponseData, producedAt),
        (ASN_TAG_CLASS_UNIVERSAL | (24 << 2)),
        0,
        &GeneralizedTime_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "producedAt"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ResponseData, responses),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &responses_5_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "responses"
    },
    {
        ATF_POINTER, 1, offsetof(struct ResponseData, responseExtensions),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &Extensions_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "responseExtensions"
    },
};
static const ber_tlv_tag_t ResponseData_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ResponseData_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 3, 0, 0 }, /* responses */
    { (ASN_TAG_CLASS_UNIVERSAL | (24 << 2)), 2, 0, 0 }, /* producedAt */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 1 }, /* byName */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 4, -1, 0 }, /* responseExtensions */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 1, 0, 0 } /* byKey */
};
static asn_SEQUENCE_specifics_t asn_SPC_ResponseData_specs_1 = {
    sizeof(struct ResponseData),
    offsetof(struct ResponseData, _asn_ctx),
    asn_MAP_ResponseData_tag2el_1,
    6,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t ResponseData_desc = {
    "ResponseData",
    "ResponseData",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ResponseData_desc_tags_1,
    sizeof(ResponseData_desc_tags_1)
    / sizeof(ResponseData_desc_tags_1[0]), /* 1 */
    ResponseData_desc_tags_1,    /* Same as above */
    sizeof(ResponseData_desc_tags_1)
    / sizeof(ResponseData_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ResponseData_1,
    5,    /* Elements count */
    &asn_SPC_ResponseData_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_ResponseData_desc(void)
{
    return &ResponseData_desc;
}
