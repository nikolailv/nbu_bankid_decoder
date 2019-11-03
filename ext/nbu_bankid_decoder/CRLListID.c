/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "CRLListID.h"

#include "asn_internal.h"

#include "CrlValidatedID.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/CRLListID.c"

static asn_TYPE_member_t asn_MBR_crls_2[] = {
    {
        ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &CrlValidatedID_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        ""
    },
};
static const ber_tlv_tag_t crls_desc_tags_2[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_crls_specs_2 = {
    sizeof(struct crls),
    offsetof(struct crls, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t crls_2_desc = {
    "crls",
    "crls",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    crls_desc_tags_2,
    sizeof(crls_desc_tags_2)
    / sizeof(crls_desc_tags_2[0]), /* 1 */
    crls_desc_tags_2,    /* Same as above */
    sizeof(crls_desc_tags_2)
    / sizeof(crls_desc_tags_2[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_crls_2,
    1,    /* Single element */
    &asn_SPC_crls_specs_2    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_CRLListID_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct CRLListID, crls),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &crls_2_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "crls"
    },
};
static const ber_tlv_tag_t CRLListID_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CRLListID_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 0 } /* crls */
};
static asn_SEQUENCE_specifics_t asn_SPC_CRLListID_specs_1 = {
    sizeof(struct CRLListID),
    offsetof(struct CRLListID, _asn_ctx),
    asn_MAP_CRLListID_tag2el_1,
    1,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t CRLListID_desc = {
    "CRLListID",
    "CRLListID",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    CRLListID_desc_tags_1,
    sizeof(CRLListID_desc_tags_1)
    / sizeof(CRLListID_desc_tags_1[0]), /* 1 */
    CRLListID_desc_tags_1,    /* Same as above */
    sizeof(CRLListID_desc_tags_1)
    / sizeof(CRLListID_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_CRLListID_1,
    1,    /* Elements count */
    &asn_SPC_CRLListID_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_CRLListID_desc(void)
{
    return &CRLListID_desc;
}
