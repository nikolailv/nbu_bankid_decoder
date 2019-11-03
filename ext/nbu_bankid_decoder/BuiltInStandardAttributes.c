/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "BuiltInStandardAttributes.h"

#include "asn_internal.h"

#include "CountryName.h"
#include "AdministrationDomainName.h"
#include "PrivateDomainName.h"
#include "PersonalName.h"
#include "OrganizationalUnitNames.h"
#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/BuiltInStandardAttributes.c"

static asn_TYPE_member_t asn_MBR_BuiltInStandardAttributes_1[] = {
    {
        ATF_POINTER, 9, offsetof(struct BuiltInStandardAttributes, country_name),
        (ASN_TAG_CLASS_APPLICATION | (1 << 2)),
        0,
        &CountryName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "country-name"
    },
    {
        ATF_POINTER, 8, offsetof(struct BuiltInStandardAttributes, administration_domain_name),
        (ASN_TAG_CLASS_APPLICATION | (2 << 2)),
        0,
        &AdministrationDomainName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "administration-domain-name"
    },
    {
        ATF_POINTER, 7, offsetof(struct BuiltInStandardAttributes, network_address),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &NetworkAddress_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "network-address"
    },
    {
        ATF_POINTER, 6, offsetof(struct BuiltInStandardAttributes, terminal_identifier),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &TerminalIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "terminal-identifier"
    },
    {
        ATF_POINTER, 5, offsetof(struct BuiltInStandardAttributes, private_domain_name),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &PrivateDomainName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "private-domain-name"
    },
    {
        ATF_POINTER, 4, offsetof(struct BuiltInStandardAttributes, organization_name),
        (ASN_TAG_CLASS_CONTEXT | (3 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &OrganizationName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "organization-name"
    },
    {
        ATF_POINTER, 3, offsetof(struct BuiltInStandardAttributes, numeric_user_identifier),
        (ASN_TAG_CLASS_CONTEXT | (4 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &NumericUserIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "numeric-user-identifier"
    },
    {
        ATF_POINTER, 2, offsetof(struct BuiltInStandardAttributes, personal_name),
        (ASN_TAG_CLASS_CONTEXT | (5 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &PersonalName_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "personal-name"
    },
    {
        ATF_POINTER, 1, offsetof(struct BuiltInStandardAttributes, organizational_unit_names),
        (ASN_TAG_CLASS_CONTEXT | (6 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &OrganizationalUnitNames_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "organizational-unit-names"
    },
};
static const ber_tlv_tag_t BuiltInStandardAttributes_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_BuiltInStandardAttributes_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (1 << 2)), 0, 0, 0 }, /* country-name */
    { (ASN_TAG_CLASS_APPLICATION | (2 << 2)), 1, 0, 0 }, /* administration-domain-name */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 2, 0, 0 }, /* network-address */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 3, 0, 0 }, /* terminal-identifier */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 4, 0, 0 }, /* private-domain-name */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 5, 0, 0 }, /* organization-name */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 6, 0, 0 }, /* numeric-user-identifier */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 7, 0, 0 }, /* personal-name */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 8, 0, 0 } /* organizational-unit-names */
};
static asn_SEQUENCE_specifics_t asn_SPC_BuiltInStandardAttributes_specs_1 = {
    sizeof(struct BuiltInStandardAttributes),
    offsetof(struct BuiltInStandardAttributes, _asn_ctx),
    asn_MAP_BuiltInStandardAttributes_tag2el_1,
    9,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t BuiltInStandardAttributes_desc = {
    "BuiltInStandardAttributes",
    "BuiltInStandardAttributes",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    BuiltInStandardAttributes_desc_tags_1,
    sizeof(BuiltInStandardAttributes_desc_tags_1)
    / sizeof(BuiltInStandardAttributes_desc_tags_1[0]), /* 1 */
    BuiltInStandardAttributes_desc_tags_1,    /* Same as above */
    sizeof(BuiltInStandardAttributes_desc_tags_1)
    / sizeof(BuiltInStandardAttributes_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_BuiltInStandardAttributes_1,
    9,    /* Elements count */
    &asn_SPC_BuiltInStandardAttributes_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_BuiltInStandardAttributes_desc(void)
{
    return &BuiltInStandardAttributes_desc;
}
