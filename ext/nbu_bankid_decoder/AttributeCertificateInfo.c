/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "AttributeCertificateInfo.h"

#include "asn_internal.h"

#include "Extensions.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/AttributeCertificateInfo.c"

static asn_TYPE_member_t asn_MBR_AttributeCertificateInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, version),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &AttCertVersion_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "version"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, holder),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &Holder_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "holder"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, issuer),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &AttCertIssuer_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuer"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, signature),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "signature"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, serialNumber),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &CertificateSerialNumber_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "serialNumber"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, attrCertValidityPeriod),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AttCertValidityPeriod_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "attrCertValidityPeriod"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfo, attributes),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &SeqAttributes_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "attributes"
    },
    {
        ATF_POINTER, 2, offsetof(struct AttributeCertificateInfo, issuerUniqueID),
        (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
        0,
        &UniqueIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuerUniqueID"
    },
    {
        ATF_POINTER, 1, offsetof(struct AttributeCertificateInfo, extensions),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &Extensions_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "extensions"
    },
};
static const ber_tlv_tag_t AttributeCertificateInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_AttributeCertificateInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 4, -1, 0 }, /* serialNumber */
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 7, 0, 0 }, /* issuerUniqueID */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 5 }, /* holder */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, -1, 4 }, /* v1Form */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 3, -2, 3 }, /* signature */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 5, -3, 2 }, /* attrCertValidityPeriod */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 6, -4, 1 }, /* attributes */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 8, -5, 0 }, /* extensions */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 2, 0, 0 } /* v2Form */
};
static asn_SEQUENCE_specifics_t asn_SPC_AttributeCertificateInfo_specs_1 = {
    sizeof(struct AttributeCertificateInfo),
    offsetof(struct AttributeCertificateInfo, _asn_ctx),
    asn_MAP_AttributeCertificateInfo_tag2el_1,
    10,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t AttributeCertificateInfo_desc = {
    "AttributeCertificateInfo",
    "AttributeCertificateInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    AttributeCertificateInfo_desc_tags_1,
    sizeof(AttributeCertificateInfo_desc_tags_1)
    / sizeof(AttributeCertificateInfo_desc_tags_1[0]), /* 1 */
    AttributeCertificateInfo_desc_tags_1,    /* Same as above */
    sizeof(AttributeCertificateInfo_desc_tags_1)
    / sizeof(AttributeCertificateInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_AttributeCertificateInfo_1,
    9,    /* Elements count */
    &asn_SPC_AttributeCertificateInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_AttributeCertificateInfo_desc(void)
{
    return &AttributeCertificateInfo_desc;
}
