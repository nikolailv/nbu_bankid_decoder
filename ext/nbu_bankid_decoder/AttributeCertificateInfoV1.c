/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "AttributeCertificateInfoV1.h"

#include "asn_internal.h"

#include "Extensions.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/AttributeCertificateInfoV1.c"

static int asn_DFL_2_set_0(int set_value, void **sptr)
{
    AttCertVersionV1_t *st = *sptr;

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
static asn_TYPE_member_t asn_MBR_subject_3[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct subject, choice.baseCertificateID),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &IssuerSerial_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "baseCertificateID"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct subject, choice.subjectName),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &GeneralNames_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "subjectName"
    },
};
static const asn_TYPE_tag2member_t asn_MAP_subject_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* baseCertificateID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* subjectName */
};
static asn_CHOICE_specifics_t asn_SPC_subject_specs_3 = {
    sizeof(struct subject),
    offsetof(struct subject, _asn_ctx),
    offsetof(struct subject, present),
    sizeof(((struct subject *)0)->present),
    asn_MAP_subject_tag2el_3,
    2,    /* Count of tags in the map */
    0,
    -1    /* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t subject_3_desc = {
    "subject",
    "subject",
    CHOICE_free,
    CHOICE_print,
    CHOICE_constraint,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    CHOICE_outmost_tag,
    0,    /* No effective tags (pointer) */
    0,    /* No effective tags (count) */
    0,    /* No tags (pointer) */
    0,    /* No tags (count) */
    0,    /* No PER visible constraints */
    asn_MBR_subject_3,
    2,    /* Elements count */
    &asn_SPC_subject_specs_3    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_AttributeCertificateInfoV1_1[] = {
    {
        ATF_POINTER, 1, offsetof(struct AttributeCertificateInfoV1, version),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &AttCertVersionV1_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        asn_DFL_2_set_0,    /* DEFAULT 0 */
        "version"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfoV1, subject),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &subject_3_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "subject"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfoV1, issuer),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &GeneralNames_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuer"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfoV1, signature),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "signature"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfoV1, serialNumber),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &CertificateSerialNumber_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "serialNumber"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfoV1, attCertValidityPeriod),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AttCertValidityPeriod_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "attCertValidityPeriod"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AttributeCertificateInfoV1, attributes),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &SeqAttributes_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "attributes"
    },
    {
        ATF_POINTER, 2, offsetof(struct AttributeCertificateInfoV1, issuerUniqueID),
        (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
        0,
        &UniqueIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "issuerUniqueID"
    },
    {
        ATF_POINTER, 1, offsetof(struct AttributeCertificateInfoV1, extensions),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &Extensions_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "extensions"
    },
};
static const ber_tlv_tag_t AttributeCertificateInfoV1_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_AttributeCertificateInfoV1_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 4, -1, 0 }, /* serialNumber */
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 7, 0, 0 }, /* issuerUniqueID */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 4 }, /* issuer */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 3, -1, 3 }, /* signature */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 5, -2, 2 }, /* attCertValidityPeriod */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 6, -3, 1 }, /* attributes */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 8, -4, 0 }, /* extensions */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 1, 0, 0 }, /* baseCertificateID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* subjectName */
};
static asn_SEQUENCE_specifics_t asn_SPC_AttributeCertificateInfoV1_specs_1 = {
    sizeof(struct AttributeCertificateInfoV1),
    offsetof(struct AttributeCertificateInfoV1, _asn_ctx),
    asn_MAP_AttributeCertificateInfoV1_tag2el_1,
    10,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t AttributeCertificateInfoV1_desc = {
    "AttributeCertificateInfoV1",
    "AttributeCertificateInfoV1",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    AttributeCertificateInfoV1_desc_tags_1,
    sizeof(AttributeCertificateInfoV1_desc_tags_1)
    / sizeof(AttributeCertificateInfoV1_desc_tags_1[0]), /* 1 */
    AttributeCertificateInfoV1_desc_tags_1,    /* Same as above */
    sizeof(AttributeCertificateInfoV1_desc_tags_1)
    / sizeof(AttributeCertificateInfoV1_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_AttributeCertificateInfoV1_1,
    9,    /* Elements count */
    &asn_SPC_AttributeCertificateInfoV1_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_AttributeCertificateInfoV1_desc(void)
{
    return &AttributeCertificateInfoV1_desc;
}
