/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "NetworkAddress.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/NetworkAddress.c"

int
NetworkAddress_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
        asn_app_constraint_failed_f *ctfailcb, void *app_key)
{
    /* Replace with underlying type checker */
    td->check_constraints = X121Address_desc.check_constraints;
    return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using X121Address,
 * so here we adjust the DEF accordingly.
 */
static void
NetworkAddress_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td)
{
    td->free_struct    = X121Address_desc.free_struct;
    td->print_struct   = X121Address_desc.print_struct;
    td->check_constraints = X121Address_desc.check_constraints;
    td->ber_decoder    = X121Address_desc.ber_decoder;
    td->der_encoder    = X121Address_desc.der_encoder;
    td->xer_decoder    = X121Address_desc.xer_decoder;
    td->xer_encoder    = X121Address_desc.xer_encoder;
    td->uper_decoder   = X121Address_desc.uper_decoder;
    td->uper_encoder   = X121Address_desc.uper_encoder;
    if (!td->per_constraints) {
        td->per_constraints = X121Address_desc.per_constraints;
    }
    td->elements       = X121Address_desc.elements;
    td->elements_count = X121Address_desc.elements_count;
    td->specifics      = X121Address_desc.specifics;
}

void
NetworkAddress_free(asn_TYPE_descriptor_t *td,
        void *struct_ptr, int contents_only)
{
    NetworkAddress_1_inherit_TYPE_descriptor(td);
    td->free_struct(td, struct_ptr, contents_only);
}

int
NetworkAddress_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
        int ilevel, asn_app_consume_bytes_f *cb, void *app_key)
{
    NetworkAddress_1_inherit_TYPE_descriptor(td);
    return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
NetworkAddress_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const void *bufptr, size_t size, int tag_mode)
{
    NetworkAddress_1_inherit_TYPE_descriptor(td);
    return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
NetworkAddress_encode_der(asn_TYPE_descriptor_t *td,
        void *structure, int tag_mode, ber_tlv_tag_t tag,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    NetworkAddress_1_inherit_TYPE_descriptor(td);
    return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
NetworkAddress_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
        void **structure, const char *opt_mname, const void *bufptr, size_t size)
{
    NetworkAddress_1_inherit_TYPE_descriptor(td);
    return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
NetworkAddress_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
        int ilevel, enum xer_encoder_flags_e flags,
        asn_app_consume_bytes_f *cb, void *app_key)
{
    NetworkAddress_1_inherit_TYPE_descriptor(td);
    return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static const ber_tlv_tag_t NetworkAddress_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (18 << 2))
};
asn_TYPE_descriptor_t NetworkAddress_desc = {
    "NetworkAddress",
    "NetworkAddress",
    NetworkAddress_free,
    NetworkAddress_print,
    NetworkAddress_constraint,
    NetworkAddress_decode_ber,
    NetworkAddress_encode_der,
    NetworkAddress_decode_xer,
    NetworkAddress_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    NetworkAddress_desc_tags_1,
    sizeof(NetworkAddress_desc_tags_1)
    / sizeof(NetworkAddress_desc_tags_1[0]), /* 1 */
    NetworkAddress_desc_tags_1,    /* Same as above */
    sizeof(NetworkAddress_desc_tags_1)
    / sizeof(NetworkAddress_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    0, 0,    /* No members */
    0    /* No specifics */
};

asn_TYPE_descriptor_t *get_NetworkAddress_desc(void)
{
    return &NetworkAddress_desc;
}
