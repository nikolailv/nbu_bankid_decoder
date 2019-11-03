/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "CertID.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/CertID.c"

static asn_TYPE_member_t asn_MBR_CertID_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct CertID, hashAlgorithm),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "hashAlgorithm"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct CertID, issuerNameHash),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuerNameHash"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct CertID, issuerKeyHash),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuerKeyHash"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct CertID, serialNumber),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &CertificateSerialNumber_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "serialNumber"
    },
};
static const ber_tlv_tag_t CertID_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CertID_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 3, 0, 0 }, /* serialNumber */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, 0, 1 }, /* issuerNameHash */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 2, -1, 0 }, /* issuerKeyHash */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 0 } /* hashAlgorithm */
};
static asn_SEQUENCE_specifics_t asn_SPC_CertID_specs_1 = {
    sizeof(struct CertID),
    offsetof(struct CertID, _asn_ctx),
    asn_MAP_CertID_tag2el_1,
    4,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t CertID_desc = {
    "CertID",
    "CertID",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    CertID_desc_tags_1,
    sizeof(CertID_desc_tags_1)
    / sizeof(CertID_desc_tags_1[0]), /* 1 */
    CertID_desc_tags_1,    /* Same as above */
    sizeof(CertID_desc_tags_1)
    / sizeof(CertID_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_CertID_1,
    4,    /* Elements count */
    &asn_SPC_CertID_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_CertID_desc(void)
{
    return &CertID_desc;
}
