/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "RevocationValues.h"

#include "asn_internal.h"

#include "CertificateList.h"
#include "BasicOCSPResponse.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/RevocationValues.c"

static asn_TYPE_member_t asn_MBR_crlVals_2[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &CertificateList_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t crlVals_desc_tags_2[] = {
    (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_crlVals_specs_2 = {
    sizeof(struct crlVals),
    offsetof(struct crlVals, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t crlVals_2_desc = {
    "crlVals",
    "crlVals",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    crlVals_desc_tags_2,
    sizeof(crlVals_desc_tags_2)
    / sizeof(crlVals_desc_tags_2[0]), /* 2 */
    crlVals_desc_tags_2,    /* Same as above */
    sizeof(crlVals_desc_tags_2)
    / sizeof(crlVals_desc_tags_2[0]), /* 2 */
    0,    /* No PER visible constraints */
    asn_MBR_crlVals_2,
    1,    /* Single element */
    &asn_SPC_crlVals_specs_2    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ocspVals_4[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &BasicOCSPResponse_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t ocspVals_desc_tags_4[] = {
    (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ocspVals_specs_4 = {
    sizeof(struct ocspVals),
    offsetof(struct ocspVals, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t ocspVals_4_desc = {
    "ocspVals",
    "ocspVals",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ocspVals_desc_tags_4,
    sizeof(ocspVals_desc_tags_4)
    / sizeof(ocspVals_desc_tags_4[0]), /* 2 */
    ocspVals_desc_tags_4,    /* Same as above */
    sizeof(ocspVals_desc_tags_4)
    / sizeof(ocspVals_desc_tags_4[0]), /* 2 */
    0,    /* No PER visible constraints */
    asn_MBR_ocspVals_4,
    1,    /* Single element */
    &asn_SPC_ocspVals_specs_4    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_RevocationValues_1[] = {
    {
        ATF_POINTER, 2, offsetof(struct RevocationValues, crlVals),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        0,
        &crlVals_2_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "crlVals"
    },
    {
        ATF_POINTER, 1, offsetof(struct RevocationValues, ocspVals),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        0,
        &ocspVals_4_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "ocspVals"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct RevocationValues, otherRevVals),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &OtherRevVals_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "otherRevVals"
    },
};
static const ber_tlv_tag_t RevocationValues_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RevocationValues_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* crlVals */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ocspVals */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* otherRevVals */
};
static asn_SEQUENCE_specifics_t asn_SPC_RevocationValues_specs_1 = {
    sizeof(struct RevocationValues),
    offsetof(struct RevocationValues, _asn_ctx),
    asn_MAP_RevocationValues_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t RevocationValues_desc = {
    "RevocationValues",
    "RevocationValues",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    RevocationValues_desc_tags_1,
    sizeof(RevocationValues_desc_tags_1)
    / sizeof(RevocationValues_desc_tags_1[0]), /* 1 */
    RevocationValues_desc_tags_1,    /* Same as above */
    sizeof(RevocationValues_desc_tags_1)
    / sizeof(RevocationValues_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_RevocationValues_1,
    3,    /* Elements count */
    &asn_SPC_RevocationValues_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_RevocationValues_desc(void)
{
    return &RevocationValues_desc;
}
