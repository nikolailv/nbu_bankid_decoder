/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "DisplayText.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/DisplayText.c"

static int check_permitted_alphabet_2(const void *sptr)
{
    /* The underlying type is VisibleString */
    const VisibleString_t *st = (const VisibleString_t *)sptr;
    const uint8_t *ch = st->buf;
    const uint8_t *end = ch + st->size;

    for (; ch < end; ch++) {
        uint8_t cv = *ch;
        if (!(cv >= 32 && cv <= 126)) {
            return -1;
        }
    }
    return 0;
}

static int check_permitted_alphabet_3(const void *sptr)
{
    /* The underlying type is BMPString */
    const BMPString_t *st = (const BMPString_t *)sptr;
    const uint8_t *ch = st->buf;
    const uint8_t *end = ch + st->size;

    if (st->size % 2) {
        return -1;    /* (size%2)! */
    }
    for (; ch < end; ch += 2) {
        uint16_t cv = (ch[0] << 8)
                | ch[1];
        if (!(cv <= 65533)) {
            return -1;
        }
    }
    return 0;
}

static int
memb_visibleString_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const VisibleString_t *st = (const VisibleString_t *)sptr;
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    size = st->size;

    if ((size >= 1 && size <= 200)
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
memb_bmpString_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const BMPString_t *st = (const BMPString_t *)sptr;
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    size = st->size >> 1;    /* 2 byte per character */

    if ((size >= 1 && size <= 200)
            && !check_permitted_alphabet_3(st)) {
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
memb_utf8String_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    const UTF8String_t *st = (const UTF8String_t *)sptr;
    size_t size;

    if (!sptr) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: value not given (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    size = UTF8String_length(st);
    if ((ssize_t)size < 0) {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: UTF-8: broken encoding (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }

    if ((size >= 1 && size <= 200)) {
        /* Constraint check succeeded */
        return 0;
    } else {
        ASN__CTFAIL(app_key, td, sptr,
                "%s: constraint failed (%s:%d)",
                td->name, FILE_MARKER, __LINE__);
        return -1;
    }
}

static asn_TYPE_member_t asn_MBR_DisplayText_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct DisplayText, choice.visibleString),
        (ASN_TAG_CLASS_UNIVERSAL | (26 << 2)),
        0,
        &VisibleString_desc,
        memb_visibleString_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "visibleString"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct DisplayText, choice.bmpString),
        (ASN_TAG_CLASS_UNIVERSAL | (30 << 2)),
        0,
        &BMPString_desc,
        memb_bmpString_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "bmpString"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct DisplayText, choice.utf8String),
        (ASN_TAG_CLASS_UNIVERSAL | (12 << 2)),
        0,
        &UTF8String_desc,
        memb_utf8String_constraint_1,
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "utf8String"
    },
};
static const asn_TYPE_tag2member_t asn_MAP_DisplayText_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (12 << 2)), 2, 0, 0 }, /* utf8String */
    { (ASN_TAG_CLASS_UNIVERSAL | (26 << 2)), 0, 0, 0 }, /* visibleString */
    { (ASN_TAG_CLASS_UNIVERSAL | (30 << 2)), 1, 0, 0 } /* bmpString */
};
static asn_CHOICE_specifics_t asn_SPC_DisplayText_specs_1 = {
    sizeof(struct DisplayText),
    offsetof(struct DisplayText, _asn_ctx),
    offsetof(struct DisplayText, present),
    sizeof(((struct DisplayText *)0)->present),
    asn_MAP_DisplayText_tag2el_1,
    3,    /* Count of tags in the map */
    0,
    -1    /* Extensions start */
};
asn_TYPE_descriptor_t DisplayText_desc = {
    "DisplayText",
    "DisplayText",
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
    asn_MBR_DisplayText_1,
    3,    /* Elements count */
    &asn_SPC_DisplayText_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_DisplayText_desc(void)
{
    return &DisplayText_desc;
}
