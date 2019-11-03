/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "FreshestCRL.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/FreshestCRL.c"

int
FreshestCRL_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
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

/*
 * This type is implemented using CRLDistributionPoints,
 * so here we adjust the DEF accordingly.
 */
static void
FreshestCRL_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = CRLDistributionPoints_desc.free_struct;
    td->print_struct   = CRLDistributionPoints_desc.print_struct;
    td->check_constraints = CRLDistributionPoints_desc.check_constraints;
    td->ber_decoder    = CRLDistributionPoints_desc.ber_decoder;
    td->der_encoder    = CRLDistributionPoints_desc.der_encoder;
    td->xer_decoder    = CRLDistributionPoints_desc.xer_decoder;
    td->xer_encoder    = CRLDistributionPoints_desc.xer_encoder;
    td->uper_decoder   = CRLDistributionPoints_desc.uper_decoder;
    td->uper_encoder   = CRLDistributionPoints_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = CRLDistributionPoints_desc.per_constraints;
    }
    td->elements       = CRLDistributionPoints_desc.elements;
    td->elements_count = CRLDistributionPoints_desc.elements_count;
    td->specifics      = CRLDistributionPoints_desc.specifics;
}

void
FreshestCRL_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    FreshestCRL_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
FreshestCRL_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    FreshestCRL_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
FreshestCRL_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    FreshestCRL_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
FreshestCRL_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    FreshestCRL_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
FreshestCRL_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    FreshestCRL_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
FreshestCRL_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    FreshestCRL_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t FreshestCRL_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
asn_TYPE_descriptor_t FreshestCRL_desc = {
    "FreshestCRL",
    "FreshestCRL",
    FreshestCRL_free,
    FreshestCRL_print,
    FreshestCRL_constraint,
    FreshestCRL_decode_ber,
    FreshestCRL_encode_der,
    FreshestCRL_decode_xer,
    FreshestCRL_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    FreshestCRL_desc_tags_1,
    sizeof(FreshestCRL_desc_tags_1)
    / sizeof(FreshestCRL_desc_tags_1[0]), /* 1 */
    FreshestCRL_desc_tags_1,    /* Same as above */
    sizeof(FreshestCRL_desc_tags_1)
    / sizeof(FreshestCRL_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* Defined elsewhere */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_FreshestCRL_desc(void)
{
    return &FreshestCRL_desc;
}
