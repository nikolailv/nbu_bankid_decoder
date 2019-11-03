/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "SignaturePolicyId.h"

#include "asn_internal.h"

#include "SigPolicyQualifierInfo.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/SignaturePolicyId.c"

static int
memb_sigPolicyQualifiers_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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

static asn_TYPE_member_t asn_MBR_sigPolicyQualifiers_4[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &SigPolicyQualifierInfo_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t sigPolicyQualifiers_desc_tags_4[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_sigPolicyQualifiers_specs_4 = {
    sizeof(struct sigPolicyQualifiers),
    offsetof(struct sigPolicyQualifiers, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t sigPolicyQualifiers_4_desc = {
    "sigPolicyQualifiers",
    "sigPolicyQualifiers",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    sigPolicyQualifiers_desc_tags_4,
    sizeof(sigPolicyQualifiers_desc_tags_4)
    / sizeof(sigPolicyQualifiers_desc_tags_4[0]), /* 1 */
    sigPolicyQualifiers_desc_tags_4,    /* Same as above */
    sizeof(sigPolicyQualifiers_desc_tags_4)
    / sizeof(sigPolicyQualifiers_desc_tags_4[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_sigPolicyQualifiers_4,
    1,    /* Single element */
    &asn_SPC_sigPolicyQualifiers_specs_4    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_SignaturePolicyId_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct SignaturePolicyId, sigPolicyId),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &SigPolicyId_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "sigPolicyId"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct SignaturePolicyId, sigPolicyHash),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &SigPolicyHash_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "sigPolicyHash"
    },
    {
        ATF_POINTER, 1, offsetof(struct SignaturePolicyId, sigPolicyQualifiers),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &sigPolicyQualifiers_4_desc,
        memb_sigPolicyQualifiers_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "sigPolicyQualifiers"
    },
};
static const ber_tlv_tag_t SignaturePolicyId_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SignaturePolicyId_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* sigPolicyId */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 1 }, /* sigPolicyHash */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, -1, 0 } /* sigPolicyQualifiers */
};
static asn_SEQUENCE_specifics_t asn_SPC_SignaturePolicyId_specs_1 = {
    sizeof(struct SignaturePolicyId),
    offsetof(struct SignaturePolicyId, _asn_ctx),
    asn_MAP_SignaturePolicyId_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t SignaturePolicyId_desc = {
    "SignaturePolicyId",
    "SignaturePolicyId",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    SignaturePolicyId_desc_tags_1,
    sizeof(SignaturePolicyId_desc_tags_1)
    / sizeof(SignaturePolicyId_desc_tags_1[0]), /* 1 */
    SignaturePolicyId_desc_tags_1,    /* Same as above */
    sizeof(SignaturePolicyId_desc_tags_1)
    / sizeof(SignaturePolicyId_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_SignaturePolicyId_1,
    3,    /* Elements count */
    &asn_SPC_SignaturePolicyId_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_SignaturePolicyId_desc(void)
{
    return &SignaturePolicyId_desc;
}
