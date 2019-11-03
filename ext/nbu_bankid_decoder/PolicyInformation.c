/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "PolicyInformation.h"

#include "asn_internal.h"

#include "PolicyQualifierInfo.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/PolicyInformation.c"

static int
memb_policyQualifiers_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    /* Determine the number of elements */
    size = _A_CSEQUENCE_FROM_VOID(sptr)->count;

    if ((size >= 1)) {
        /* Perform validation of the inner elements */
        return td->check_constraints(td, sptr, ctfailcb, app_key);
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static asn_TYPE_member_t asn_MBR_policyQualifiers_3[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &PolicyQualifierInfo_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t policyQualifiers_desc_tags_3[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_policyQualifiers_specs_3 = {
    sizeof(struct policyQualifiers),
    offsetof(struct policyQualifiers, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t policyQualifiers_3_desc = {
    "policyQualifiers",
    "policyQualifiers",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    policyQualifiers_desc_tags_3,
    sizeof(policyQualifiers_desc_tags_3)
    / sizeof(policyQualifiers_desc_tags_3[0]), /* 1 */
    policyQualifiers_desc_tags_3,    /* Same as above */
    sizeof(policyQualifiers_desc_tags_3)
    / sizeof(policyQualifiers_desc_tags_3[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_policyQualifiers_3,
    1,    /* Single element */
    &asn_SPC_policyQualifiers_specs_3    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_PolicyInformation_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct PolicyInformation, policyIdentifier),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &CertPolicyId_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "policyIdentifier"
    },
    {
        ATF_POINTER, 1, offsetof(struct PolicyInformation, policyQualifiers),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &policyQualifiers_3_desc,
        memb_policyQualifiers_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "policyQualifiers"
    },
};
static const ber_tlv_tag_t PolicyInformation_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PolicyInformation_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* policyIdentifier */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 } /* policyQualifiers */
};
static asn_SEQUENCE_specifics_t asn_SPC_PolicyInformation_specs_1 = {
    sizeof(struct PolicyInformation),
    offsetof(struct PolicyInformation, _asn_ctx),
    asn_MAP_PolicyInformation_tag2el_1,
    2,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t PolicyInformation_desc = {
    "PolicyInformation",
    "PolicyInformation",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    PolicyInformation_desc_tags_1,
    sizeof(PolicyInformation_desc_tags_1)
    / sizeof(PolicyInformation_desc_tags_1[0]), /* 1 */
    PolicyInformation_desc_tags_1,    /* Same as above */
    sizeof(PolicyInformation_desc_tags_1)
    / sizeof(PolicyInformation_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_PolicyInformation_1,
    2,    /* Elements count */
    &asn_SPC_PolicyInformation_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_PolicyInformation_desc(void)
{
    return &PolicyInformation_desc;
}
