/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "ObjectDigestInfo.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/ObjectDigestInfo.c"

static int
digestedObjectType_2_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = ENUMERATED_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ENUMERATED,
 * so here we adjust the DEF accordingly.
 */
static void
digestedObjectType_2_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = ENUMERATED_desc.free_struct;
    td->print_struct   = ENUMERATED_desc.print_struct;
    td->check_constraints = ENUMERATED_desc.check_constraints;
    td->ber_decoder    = ENUMERATED_desc.ber_decoder;
    td->der_encoder    = ENUMERATED_desc.der_encoder;
    td->xer_decoder    = ENUMERATED_desc.xer_decoder;
    td->xer_encoder    = ENUMERATED_desc.xer_encoder;
    td->uper_decoder   = ENUMERATED_desc.uper_decoder;
    td->uper_encoder   = ENUMERATED_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = ENUMERATED_desc.per_constraints;
    }
    td->elements       = ENUMERATED_desc.elements;
    td->elements_count = ENUMERATED_desc.elements_count;
    /* td->specifics      = ENUMERATED_desc.specifics;    // Defined explicitly */
}

static void
digestedObjectType_2_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    digestedObjectType_2_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

static int
digestedObjectType_2_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    digestedObjectType_2_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
digestedObjectType_2_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    digestedObjectType_2_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
digestedObjectType_2_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    digestedObjectType_2_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
digestedObjectType_2_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    digestedObjectType_2_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
digestedObjectType_2_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    digestedObjectType_2_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const asn_INTEGER_enum_map_t asn_MAP_digestedObjectType_value2enum_2[] = {
    { 0,    9,    "publicKey" },
    { 1,    13,    "publicKeyCert" },
    { 2,    16,    "otherObjectTypes" }
};
static const unsigned int asn_MAP_digestedObjectType_enum2value_2[] = {
    2,    /* otherObjectTypes(2) */
    0,    /* publicKey(0) */
    1    /* publicKeyCert(1) */
};
static asn_INTEGER_specifics_t asn_SPC_digestedObjectType_specs_2 = {
    asn_MAP_digestedObjectType_value2enum_2,    /* "tag" => N; sorted by tag */
    asn_MAP_digestedObjectType_enum2value_2,    /* N => "tag"; sorted by N */
    3,    /* Number of elements in the maps */
    0,    /* Enumeration is not extensible */
    1,    /* Strict enumeration */
    0,    /* Native long size */
    0
};
static const ber_tlv_tag_t digestedObjectType_desc_tags_2[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t digestedObjectType_2_desc = {
    "digestedObjectType",
    "digestedObjectType",
    digestedObjectType_2_free,
    digestedObjectType_2_print,
    digestedObjectType_2_constraint,
    digestedObjectType_2_decode_ber,
    digestedObjectType_2_encode_der,
    digestedObjectType_2_decode_xer,
    digestedObjectType_2_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    digestedObjectType_desc_tags_2,
    sizeof(digestedObjectType_desc_tags_2)
    / sizeof(digestedObjectType_desc_tags_2[0]), /* 1 */
    digestedObjectType_desc_tags_2,    /* Same as above */
    sizeof(digestedObjectType_desc_tags_2)
    / sizeof(digestedObjectType_desc_tags_2[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    &asn_SPC_digestedObjectType_specs_2    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ObjectDigestInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct ObjectDigestInfo, digestedObjectType),
        (ASN_TAG_CLASS_UNIVERSAL | (10 << 2)),
        0,
        &digestedObjectType_2_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "digestedObjectType"
    },
    {
        ATF_POINTER, 1, offsetof(struct ObjectDigestInfo, otherObjectTypeID),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &OBJECT_IDENTIFIER_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "otherObjectTypeID"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ObjectDigestInfo, digestAlgorithm),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &AlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "digestAlgorithm"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct ObjectDigestInfo, objectDigest),
        (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)),
        0,
        &BIT_STRING_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "objectDigest"
    },
};
static const ber_tlv_tag_t ObjectDigestInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ObjectDigestInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)), 3, 0, 0 }, /* objectDigest */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 1, 0, 0 }, /* otherObjectTypeID */
    { (ASN_TAG_CLASS_UNIVERSAL | (10 << 2)), 0, 0, 0 }, /* digestedObjectType */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 } /* digestAlgorithm */
};
static asn_SEQUENCE_specifics_t asn_SPC_ObjectDigestInfo_specs_1 = {
    sizeof(struct ObjectDigestInfo),
    offsetof(struct ObjectDigestInfo, _asn_ctx),
    asn_MAP_ObjectDigestInfo_tag2el_1,
    4,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t ObjectDigestInfo_desc = {
    "ObjectDigestInfo",
    "ObjectDigestInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    ObjectDigestInfo_desc_tags_1,
    sizeof(ObjectDigestInfo_desc_tags_1)
    / sizeof(ObjectDigestInfo_desc_tags_1[0]), /* 1 */
    ObjectDigestInfo_desc_tags_1,    /* Same as above */
    sizeof(ObjectDigestInfo_desc_tags_1)
    / sizeof(ObjectDigestInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ObjectDigestInfo_1,
    4,    /* Elements count */
    &asn_SPC_ObjectDigestInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_ObjectDigestInfo_desc(void)
{
    return &ObjectDigestInfo_desc;
}
