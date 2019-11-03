/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "TimeStampReq.h"

#include "asn_internal.h"

#include "Extensions.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/TimeStampReq.c"

static asn_TYPE_member_t asn_MBR_TimeStampReq_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct TimeStampReq, version),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &TSVersion_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "version"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct TimeStampReq, messageImprint),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &MessageImprint_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "messageImprint"
    },
    {
        ATF_POINTER, 4, offsetof(struct TimeStampReq, reqPolicy),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &TSAPolicyId_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "reqPolicy"
    },
    {
        ATF_POINTER, 3, offsetof(struct TimeStampReq, nonce),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "nonce"
    },
    {
        ATF_POINTER, 2, offsetof(struct TimeStampReq, certReq),
        (ASN_TAG_CLASS_UNIVERSAL | (1 << 2)),
        0,
        &BOOLEAN_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "certReq"
    },
    {
        ATF_POINTER, 1, offsetof(struct TimeStampReq, extensions),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &Extensions_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "extensions"
    },
};
static const ber_tlv_tag_t TimeStampReq_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TimeStampReq_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (1 << 2)), 4, 0, 0 }, /* certReq */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 3, -1, 0 }, /* nonce */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 2, 0, 0 }, /* reqPolicy */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 }, /* messageImprint */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 5, 0, 0 } /* extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_TimeStampReq_specs_1 = {
    sizeof(struct TimeStampReq),
    offsetof(struct TimeStampReq, _asn_ctx),
    asn_MAP_TimeStampReq_tag2el_1,
    6,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t TimeStampReq_desc = {
    "TimeStampReq",
    "TimeStampReq",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    TimeStampReq_desc_tags_1,
    sizeof(TimeStampReq_desc_tags_1)
    / sizeof(TimeStampReq_desc_tags_1[0]), /* 1 */
    TimeStampReq_desc_tags_1,    /* Same as above */
    sizeof(TimeStampReq_desc_tags_1)
    / sizeof(TimeStampReq_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_TimeStampReq_1,
    6,    /* Elements count */
    &asn_SPC_TimeStampReq_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_TimeStampReq_desc(void)
{
    return &TimeStampReq_desc;
}
