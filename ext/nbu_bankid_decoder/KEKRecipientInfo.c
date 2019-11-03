/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "KEKRecipientInfo.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/KEKRecipientInfo.c"

static asn_TYPE_member_t asn_MBR_KEKRecipientInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct KEKRecipientInfo, version),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &CMSVersion_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "version"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct KEKRecipientInfo, kekid),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &KEKIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "kekid"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct KEKRecipientInfo, keyEncryptionAlgorithm),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &KeyEncryptionAlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "keyEncryptionAlgorithm"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct KEKRecipientInfo, encryptedKey),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &EncryptedKey_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "encryptedKey"
    },
};
static const ber_tlv_tag_t KEKRecipientInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_KEKRecipientInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 3, 0, 0 }, /* encryptedKey */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 1 }, /* kekid */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, -1, 0 } /* keyEncryptionAlgorithm */
};
static asn_SEQUENCE_specifics_t asn_SPC_KEKRecipientInfo_specs_1 = {
    sizeof(struct KEKRecipientInfo),
    offsetof(struct KEKRecipientInfo, _asn_ctx),
    asn_MAP_KEKRecipientInfo_tag2el_1,
    4,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t KEKRecipientInfo_desc = {
    "KEKRecipientInfo",
    "KEKRecipientInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    KEKRecipientInfo_desc_tags_1,
    sizeof(KEKRecipientInfo_desc_tags_1)
    / sizeof(KEKRecipientInfo_desc_tags_1[0]), /* 1 */
    KEKRecipientInfo_desc_tags_1,    /* Same as above */
    sizeof(KEKRecipientInfo_desc_tags_1)
    / sizeof(KEKRecipientInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_KEKRecipientInfo_1,
    4,    /* Elements count */
    &asn_SPC_KEKRecipientInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_KEKRecipientInfo_desc(void)
{
    return &KEKRecipientInfo_desc;
}
