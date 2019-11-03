/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "ESSCertIDv2.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/ESSCertIDv2.c"

static asn_TYPE_member_t asn_MBR_ESSCertIDv2_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct ESSCertIDv2, hashAlgorithm),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "hashAlgorithm"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ESSCertIDv2, certHash),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &Hash_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "certHash"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ESSCertIDv2, issuerSerial),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &IssuerSerial_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuerSerial"
    },
};
static const ber_tlv_tag_t ESSCertIDv2_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ESSCertIDv2_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, 0, 0 }, /* certHash */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 1 }, /* hashAlgorithm */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, -1, 0 } /* issuerSerial */
};
static asn_SEQUENCE_specifics_t asn_SPC_ESSCertIDv2_specs_1 = {
    sizeof(struct ESSCertIDv2),
    offsetof(struct ESSCertIDv2, _asn_ctx),
    asn_MAP_ESSCertIDv2_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t ESSCertIDv2_desc = {
    "ESSCertIDv2",
    "ESSCertIDv2",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ESSCertIDv2_desc_tags_1,
    sizeof(ESSCertIDv2_desc_tags_1)
    / sizeof(ESSCertIDv2_desc_tags_1[0]), /* 1 */
    ESSCertIDv2_desc_tags_1,    /* Same as above */
    sizeof(ESSCertIDv2_desc_tags_1)
    / sizeof(ESSCertIDv2_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ESSCertIDv2_1,
    3,    /* Elements count */
    &asn_SPC_ESSCertIDv2_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_ESSCertIDv2_desc(void)
{
    return &ESSCertIDv2_desc;
}
