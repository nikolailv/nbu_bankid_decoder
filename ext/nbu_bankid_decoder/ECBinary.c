/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "ECBinary.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/ECBinary.c"

static int
memb_a_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    long value;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    value = *(const long *)sptr;

    if ((value >= 0 && value <= 1)) {
        /* Constraint check succeeded */
        return 0;
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static int asn_DFL_2_set_0(int set_value, void **sptr)
{
    Version_t *st = *sptr;

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
static asn_TYPE_member_t asn_MBR_ECBinary_1[] = {
    {
        ATF_POINTER, 1, offsetof(struct ECBinary, version),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        +1,    /* EXPLICIT tag at current level */
        &Version_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        asn_DFL_2_set_0,    /* DEFAULT 0 */
        "version"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ECBinary, f),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &BinaryField_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "f"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ECBinary, a),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &NativeInteger_desc,
        memb_a_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "a"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ECBinary, b),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "b"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ECBinary, n),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &INTEGER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "n"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ECBinary, bp),
        (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
        0,
        &OCTET_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "bp"
    },
};
static const ber_tlv_tag_t ECBinary_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ECBinary_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 2, 0, 1 }, /* a */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 4, -1, 0 }, /* n */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 3, 0, 1 }, /* b */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 5, -1, 0 }, /* bp */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 }, /* f */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* version */
};
static asn_SEQUENCE_specifics_t asn_SPC_ECBinary_specs_1 = {
    sizeof(struct ECBinary),
    offsetof(struct ECBinary, _asn_ctx),
    asn_MAP_ECBinary_tag2el_1,
    6,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t ECBinary_desc = {
    "ECBinary",
    "ECBinary",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ECBinary_desc_tags_1,
    sizeof(ECBinary_desc_tags_1)
    / sizeof(ECBinary_desc_tags_1[0]), /* 1 */
    ECBinary_desc_tags_1,    /* Same as above */
    sizeof(ECBinary_desc_tags_1)
    / sizeof(ECBinary_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ECBinary_1,
    6,    /* Elements count */
    &asn_SPC_ECBinary_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_ECBinary_desc(void)
{
    return &ECBinary_desc;
}
