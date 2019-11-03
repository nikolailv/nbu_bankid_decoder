/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "AccessDescription.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/AccessDescription.c"

static asn_TYPE_member_t asn_MBR_AccessDescription_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct AccessDescription, accessMethod),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &OBJECT_IDENTIFIER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "accessMethod"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct AccessDescription, accessLocation),
        -1 /* Ambiguous tag (CHOICE?) */,
        0,
        &GeneralName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "accessLocation"
    },
};
static const ber_tlv_tag_t AccessDescription_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_AccessDescription_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* accessMethod */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 1, 0, 0 }, /* otherName */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rfc822Name */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 1, 0, 0 }, /* dNSName */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 1, 0, 0 }, /* x400Address */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 1, 0, 0 }, /* directoryName */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 1, 0, 0 }, /* ediPartyName */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 1, 0, 0 }, /* uniformResourceIdentifier */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 1, 0, 0 }, /* iPAddress */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 1, 0, 0 } /* registeredID */
};
static asn_SEQUENCE_specifics_t asn_SPC_AccessDescription_specs_1 = {
    sizeof(struct AccessDescription),
    offsetof(struct AccessDescription, _asn_ctx),
    asn_MAP_AccessDescription_tag2el_1,
    10,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t AccessDescription_desc = {
    "AccessDescription",
    "AccessDescription",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    AccessDescription_desc_tags_1,
    sizeof(AccessDescription_desc_tags_1)
    / sizeof(AccessDescription_desc_tags_1[0]), /* 1 */
    AccessDescription_desc_tags_1,    /* Same as above */
    sizeof(AccessDescription_desc_tags_1)
    / sizeof(AccessDescription_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_AccessDescription_1,
    2,    /* Elements count */
    &asn_SPC_AccessDescription_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_AccessDescription_desc(void)
{
    return &AccessDescription_desc;
}
