/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "Iso4217CurrencyCode.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/Iso4217CurrencyCode.c"

static const int permitted_alphabet_table_2[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /*                  */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /*                  */
    1, 0, 0, 0, 0, 0, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9,    /* .      '() +,-./ */
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 0, 0, 21, 0, 22, /* 0123456789:  = ? */
    0, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, /*  ABCDEFGHIJKLMNO */
    38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0, 0, 0, 0, 0, /* PQRSTUVWXYZ      */
    0, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, /*  abcdefghijklmno */
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 0, 0, 0, 0, 0, /* pqrstuvwxyz      */
};

static int check_permitted_alphabet_2(const void *sptr)
{
    const int *table = permitted_alphabet_table_2;
    /* The underlying type is PrintableString */
    const PrintableString_t *st = (const PrintableString_t *)sptr;
    const uint8_t *ch = st->buf;
    const uint8_t *end = ch + st->size;

    for (; ch < end; ch++) {
        uint8_t cv = *ch;
        if (!table[cv]) {
            return -1;
        }
    }
    return 0;
}

static int
memb_alphabetic_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const PrintableString_t *st = (const PrintableString_t *)sptr;
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    size = st->size;

    if ((size == 3)
            && !check_permitted_alphabet_2(st)) {
        /* Constraint check succeeded */
        return 0;
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static int
memb_numeric_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
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

    if ((value >= 1 && value <= 999)) {
        /* Constraint check succeeded */
        return 0;
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static asn_TYPE_member_t asn_MBR_Iso4217CurrencyCode_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct Iso4217CurrencyCode, choice.alphabetic),
        (ASN_TAG_CLASS_UNIVERSAL | (19 << 2)),
        0,
        &PrintableString_desc,
        memb_alphabetic_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "alphabetic"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct Iso4217CurrencyCode, choice.numeric),
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &NativeInteger_desc,
        memb_numeric_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "numeric"
    },
};
static const asn_TYPE_tag2member_t asn_MAP_Iso4217CurrencyCode_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, 0, 0 }, /* numeric */
    { (ASN_TAG_CLASS_UNIVERSAL | (19 << 2)), 0, 0, 0 } /* alphabetic */
};
static asn_CHOICE_specifics_t asn_SPC_Iso4217CurrencyCode_specs_1 = {
    sizeof(struct Iso4217CurrencyCode),
    offsetof(struct Iso4217CurrencyCode, _asn_ctx),
    offsetof(struct Iso4217CurrencyCode, present),
    sizeof(((struct Iso4217CurrencyCode *)0)->present),
    asn_MAP_Iso4217CurrencyCode_tag2el_1,
    2,    /* Count of tags in the map */
    0,
    -1    /* Extensions start */
};
asn_TYPE_descriptor_t Iso4217CurrencyCode_desc = {
    "Iso4217CurrencyCode",
    "Iso4217CurrencyCode",
    CHOICE_free,
    CHOICE_print,
    CHOICE_constraint,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    CHOICE_outmost_tag,
    0,    /* No effective tags (pointer) */
    0,    /* No effective tags (count) */
    0,    /* No tags (pointer) */
    0,    /* No tags (count) */
    0,    /* No PER visible constraints */
    asn_MBR_Iso4217CurrencyCode_1,
    2,    /* Elements count */
    &asn_SPC_Iso4217CurrencyCode_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_Iso4217CurrencyCode_desc(void)
{
    return &Iso4217CurrencyCode_desc;
}
