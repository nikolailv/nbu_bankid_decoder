/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "AttributeValue.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/AttributeValue.c"

int
AttributeValue_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = ANY_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using ANY,
 * so here we adjust the DEF accordingly.
 */
static void
AttributeValue_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = ANY_desc.free_struct;
    td->print_struct   = ANY_desc.print_struct;
    td->check_constraints = ANY_desc.check_constraints;
    td->ber_decoder    = ANY_desc.ber_decoder;
    td->der_encoder    = ANY_desc.der_encoder;
    td->xer_decoder    = ANY_desc.xer_decoder;
    td->xer_encoder    = ANY_desc.xer_encoder;
    td->uper_decoder   = ANY_desc.uper_decoder;
    td->uper_encoder   = ANY_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = ANY_desc.per_constraints;
    }
    td->elements       = ANY_desc.elements;
    td->elements_count = ANY_desc.elements_count;
    td->specifics      = ANY_desc.specifics;
}

void
AttributeValue_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    AttributeValue_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
AttributeValue_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    AttributeValue_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
AttributeValue_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    AttributeValue_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
AttributeValue_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    AttributeValue_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
AttributeValue_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    AttributeValue_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
AttributeValue_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    AttributeValue_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

asn_TYPE_descriptor_t AttributeValue_desc = {
    "AttributeValue",
    "AttributeValue",
    AttributeValue_free,
    AttributeValue_print,
    AttributeValue_constraint,
    AttributeValue_decode_ber,
    AttributeValue_encode_der,
    AttributeValue_decode_xer,
    AttributeValue_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    0,    /* No effective tags (pointer) */
    0,    /* No effective tags (count) */
    0,    /* No tags (pointer) */
    0,    /* No tags (count) */
    0,    /* No PER visible constraints */
    0, 0,    /* No members */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_AttributeValue_desc(void)
{
    return &AttributeValue_desc;
}
