/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "CertificateLists.h"

#include "asn_internal.h"

#include "CertificateList.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/CertificateLists.c"

static asn_TYPE_member_t asn_MBR_CertificateLists_1[] = {
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
static const ber_tlv_tag_t CertificateLists_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_CertificateLists_specs_1 = {
    sizeof(struct CertificateLists),
    offsetof(struct CertificateLists, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t CertificateLists_desc = {
    "CertificateLists",
    "CertificateLists",
    SET_OF_free,
    SET_OF_print,
    SET_OF_constraint,
    SET_OF_decode_ber,
    SET_OF_encode_der,
    SET_OF_decode_xer,
    SET_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    CertificateLists_desc_tags_1,
    sizeof(CertificateLists_desc_tags_1)
    / sizeof(CertificateLists_desc_tags_1[0]), /* 1 */
    CertificateLists_desc_tags_1,    /* Same as above */
    sizeof(CertificateLists_desc_tags_1)
    / sizeof(CertificateLists_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_CertificateLists_1,
    1,    /* Single element */
    &asn_SPC_CertificateLists_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_CertificateLists_desc(void)
{
    return &CertificateLists_desc;
}
