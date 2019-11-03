/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "PasswordRecipientInfo.h"

#include "asn_internal.h"

#include "KeyDerivationAlgorithmIdentifier.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/PasswordRecipientInfo.c"

static asn_TYPE_member_t asn_MBR_PasswordRecipientInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct PasswordRecipientInfo, version),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &CMSVersion_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "version"
    },
    {
        ATF_POINTER, 1, offsetof(struct PasswordRecipientInfo, keyDerivationAlgorithm),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &KeyDerivationAlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "keyDerivationAlgorithm"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct PasswordRecipientInfo, keyEncryptionAlgorithm),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &KeyEncryptionAlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "keyEncryptionAlgorithm"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct PasswordRecipientInfo, encryptedKey),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &EncryptedKey_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "encryptedKey"
    },
};
static const ber_tlv_tag_t PasswordRecipientInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PasswordRecipientInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 3, 0, 0 }, /* encryptedKey */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 }, /* keyEncryptionAlgorithm */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 1, 0, 0 } /* keyDerivationAlgorithm */
};
static asn_SEQUENCE_specifics_t asn_SPC_PasswordRecipientInfo_specs_1 = {
    sizeof(struct PasswordRecipientInfo),
    offsetof(struct PasswordRecipientInfo, _asn_ctx),
    asn_MAP_PasswordRecipientInfo_tag2el_1,
    4,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t PasswordRecipientInfo_desc = {
    "PasswordRecipientInfo",
    "PasswordRecipientInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    PasswordRecipientInfo_desc_tags_1,
    sizeof(PasswordRecipientInfo_desc_tags_1)
    / sizeof(PasswordRecipientInfo_desc_tags_1[0]), /* 1 */
    PasswordRecipientInfo_desc_tags_1,    /* Same as above */
    sizeof(PasswordRecipientInfo_desc_tags_1)
    / sizeof(PasswordRecipientInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_PasswordRecipientInfo_1,
    4,    /* Elements count */
    &asn_SPC_PasswordRecipientInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_PasswordRecipientInfo_desc(void)
{
    return &PasswordRecipientInfo_desc;
}
