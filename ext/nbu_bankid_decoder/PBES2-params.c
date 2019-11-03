/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "PBES2-params.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/PBES2-params.c"

static asn_TYPE_member_t asn_MBR_PBES2_params_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct PBES2_params, keyDerivationFunc),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &PBES2_KDFs_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "keyDerivationFunc"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct PBES2_params, encryptionScheme),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "encryptionScheme"
    },
};
static const ber_tlv_tag_t PBES2_params_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PBES2_params_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 1 }, /* keyDerivationFunc */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, -1, 0 } /* encryptionScheme */
};
static asn_SEQUENCE_specifics_t asn_SPC_PBES2_params_specs_1 = {
    sizeof(struct PBES2_params),
    offsetof(struct PBES2_params, _asn_ctx),
    asn_MAP_PBES2_params_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t PBES2_params_desc = {
    "PBES2-params",
    "PBES2-params",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    PBES2_params_desc_tags_1,
    sizeof(PBES2_params_desc_tags_1)
    / sizeof(PBES2_params_desc_tags_1[0]), /* 1 */
    PBES2_params_desc_tags_1,    /* Same as above */
    sizeof(PBES2_params_desc_tags_1)
    / sizeof(PBES2_params_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_PBES2_params_1,
    2,    /* Elements count */
    &asn_SPC_PBES2_params_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_PBES2_params_desc(void)
{
    return &PBES2_params_desc;
}
