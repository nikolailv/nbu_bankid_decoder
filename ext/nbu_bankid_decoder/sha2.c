/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include <string.h>
#include <stddef.h>

#include "sha2.h"
#include "byte_array_internal.h"
#include "macros_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "cryptonite/sha2.c"

#define SHA224_DIGEST_SIZE ( 224 >> 3)
#define SHA256_DIGEST_SIZE ( 256 >> 3)
#define SHA384_DIGEST_SIZE ( 384 >> 3)
#define SHA512_DIGEST_SIZE ( 512 >> 3)

#define SHA256_BLOCK_SIZE  ( 512 >> 3)
#define SHA512_BLOCK_SIZE  (1024 >> 3)
#define SHA384_BLOCK_SIZE  SHA512_BLOCK_SIZE
#define SHA224_BLOCK_SIZE  SHA256_BLOCK_SIZE

struct Sha256Ctx_st {
    size_t tot_len;
    size_t len;
    uint8_t block[SHA256_BLOCK_SIZE << 1];
    uint32_t h[8];
};

struct Sha512Ctx_st {
    size_t tot_len;
    size_t len;
    uint8_t block[SHA512_BLOCK_SIZE << 1];
    uint64_t h[8];
};

typedef struct Sha256Ctx_st Sha224Ctx;
typedef struct Sha256Ctx_st Sha256Ctx;
typedef struct Sha512Ctx_st Sha384Ctx;
typedef struct Sha512Ctx_st Sha512Ctx;

struct Sha2Ctx_st {
    Sha2Variant variant;
    uint8_t k_opad[SHA512_BLOCK_SIZE];

    union {
        Sha224Ctx ctx224;
        Sha256Ctx ctx256;
        Sha384Ctx ctx384;
        Sha512Ctx ctx512;
    } type;
};

#define BASE_INIT(ctx, h0)          \
        ctx->h[0] = h0[0];          \
        ctx->h[1] = h0[1];          \
        ctx->h[2] = h0[2];          \
        ctx->h[3] = h0[3];          \
        ctx->h[4] = h0[4];          \
        ctx->h[5] = h0[5];          \
        ctx->h[6] = h0[6];          \
        ctx->h[7] = h0[7]

#define SHFR(x, n)    (x >> n)
#define ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define CH(x, y, z)  ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

#define SHA256_F1(x) (ROTR(x,  2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SHA256_F2(x) (ROTR(x,  6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SHA256_F3(x) (ROTR(x,  7) ^ ROTR(x, 18) ^ SHFR(x,  3))
#define SHA256_F4(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHFR(x, 10))

#define SHA512_F1(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define SHA512_F2(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define SHA512_F3(x) (ROTR(x,  1) ^ ROTR(x,  8) ^ SHFR(x,  7))
#define SHA512_F4(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ SHFR(x,  6))

#define UNPACK32(x, str)                            \
{                                                   \
    *((str) + 3) = (uint8_t) ((x)      );           \
    *((str) + 2) = (uint8_t) ((x) >>  8);           \
    *((str) + 1) = (uint8_t) ((x) >> 16);           \
    *((str) + 0) = (uint8_t) ((x) >> 24);           \
}

#define PACK32(str, x)                              \
{                                                   \
    *(x) =   ((uint32_t) *((str) + 3)      )|       \
             ((uint32_t) *((str) + 2) <<  8)|       \
             ((uint32_t) *((str) + 1) << 16)|       \
             ((uint32_t) *((str) + 0) << 24);       \
}

#define UNPACK64(x, str)                            \
{                                                   \
    *((str) + 7) = (uint8_t) ((x)      );           \
    *((str) + 6) = (uint8_t) ((x) >>  8);           \
    *((str) + 5) = (uint8_t) ((x) >> 16);           \
    *((str) + 4) = (uint8_t) ((x) >> 24);           \
    *((str) + 3) = (uint8_t) ((x) >> 32);           \
    *((str) + 2) = (uint8_t) ((x) >> 40);           \
    *((str) + 1) = (uint8_t) ((x) >> 48);           \
    *((str) + 0) = (uint8_t) ((x) >> 56);           \
}

#define PACK64(str, x)                               \
{                                                    \
    *(x) =   ((uint64_t) *((str) + 7)      )|        \
             ((uint64_t) *((str) + 6) <<  8)|        \
             ((uint64_t) *((str) + 5) << 16)|        \
             ((uint64_t) *((str) + 4) << 24)|        \
             ((uint64_t) *((str) + 3) << 32)|        \
             ((uint64_t) *((str) + 2) << 40)|        \
             ((uint64_t) *((str) + 1) << 48)|        \
             ((uint64_t) *((str) + 0) << 56);        \
}

#define PACK64w(str, x)                              \
{                                                    \
    *(x) =   ((uint64_t) *((str) + 7) << 32)|        \
             ((uint64_t) *((str) + 6) << 40)|        \
             ((uint64_t) *((str) + 5) << 48)|        \
             ((uint64_t) *((str) + 4) << 56)|        \
             ((uint64_t) *((str) + 3) << 0 )|        \
             ((uint64_t) *((str) + 2) << 8 )|        \
             ((uint64_t) *((str) + 1) << 16)|        \
             ((uint64_t) *((str) + 0) << 24);        \
}

/* Macros used for loops unrolling */
#define SHA256_SCR(i)                               \
{                                                   \
    w[i] =  SHA256_F4(w[i -  2]) + w[i -  7]        \
          + SHA256_F3(w[i - 15]) + w[i - 16];       \
}

#define SHA512_SCR(i)                               \
{                                                   \
    w[i] =  SHA512_F4(w[i -  2]) + w[i -  7]        \
          + SHA512_F3(w[i - 15]) + w[i - 16];       \
}

#define SHA256_EXP(a, b, c, d, e, f, g, h, j)               \
{                                                           \
    t1 = wv[h] + SHA256_F2(wv[e]) + CH(wv[e], wv[f], wv[g]) \
         + sha256_k[j] + w[j];                              \
    t2 = SHA256_F1(wv[a]) + MAJ(wv[a], wv[b], wv[c]);       \
    wv[d] += t1;                                            \
    wv[h] = t1 + t2;                                        \
}

#define SHA512_EXP(a, b, c, d, e, f, g ,h, j)               \
{                                                           \
    t1 = wv[h] + SHA512_F2(wv[e]) + CH(wv[e], wv[f], wv[g]) \
         + sha512_k[j] + w[j];                              \
    t2 = SHA512_F1(wv[a]) + MAJ(wv[a], wv[b], wv[c]);       \
    wv[d] += t1;                                            \
    wv[h] = t1 + t2;                                        \
}

#define SHA256_EXP_UNROLL(i)                                            \
        SHA256_EXP(0, 1, 2, 3, 4, 5, 6, 7, 0 + i);                      \
        SHA256_EXP(7, 0, 1, 2, 3, 4, 5, 6, 1 + i);                      \
        SHA256_EXP(6, 7, 0, 1, 2, 3, 4, 5, 2 + i);                      \
        SHA256_EXP(5, 6, 7, 0, 1, 2, 3, 4, 3 + i);                      \
        SHA256_EXP(4, 5, 6, 7, 0, 1, 2, 3, 4 + i);                      \
        SHA256_EXP(3, 4, 5, 6, 7, 0, 1, 2, 5 + i);                      \
        SHA256_EXP(2, 3, 4, 5, 6, 7, 0, 1, 6 + i);                      \
        SHA256_EXP(1, 2, 3, 4, 5, 6, 7, 0, 7 + i)

#define SHA256_SCR_UNROLL(i)                                            \
        SHA256_SCR(0 + i);                                              \
        SHA256_SCR(1 + i);                                              \
        SHA256_SCR(2 + i);                                              \
        SHA256_SCR(3 + i);                                              \
        SHA256_SCR(4 + i);                                              \
        SHA256_SCR(5 + i);                                              \
        SHA256_SCR(6 + i);                                              \
        SHA256_SCR(7 + i)


#define SHA512_EXP_UNROLL(i)                                            \
        SHA512_EXP(0, 1, 2, 3, 4, 5, 6, 7, 0 + i);                      \
        SHA512_EXP(7, 0, 1, 2, 3, 4, 5, 6, 1 + i);                      \
        SHA512_EXP(6, 7, 0, 1, 2, 3, 4, 5, 2 + i);                      \
        SHA512_EXP(5, 6, 7, 0, 1, 2, 3, 4, 3 + i);                      \
        SHA512_EXP(4, 5, 6, 7, 0, 1, 2, 3, 4 + i);                      \
        SHA512_EXP(3, 4, 5, 6, 7, 0, 1, 2, 5 + i);                      \
        SHA512_EXP(2, 3, 4, 5, 6, 7, 0, 1, 6 + i);                      \
        SHA512_EXP(1, 2, 3, 4, 5, 6, 7, 0, 7 + i)


#define SHA512_SCR_UNROLL(i)                                            \
        SHA512_SCR(0 + i);                                              \
        SHA512_SCR(1 + i);                                              \
        SHA512_SCR(2 + i);                                              \
        SHA512_SCR(3 + i);                                              \
        SHA512_SCR(4 + i);                                              \
        SHA512_SCR(5 + i);                                              \
        SHA512_SCR(6 + i);                                              \
        SHA512_SCR(7 + i)

/*init data from standart*/
static const uint32_t sha224_h0[8] = {
    0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
    0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4
};

static const uint32_t sha256_h0[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

static const uint64_t sha384_h0[8] = {
    0xcbbb9d5dc1059ed8ULL, 0x629a292a367cd507ULL,
    0x9159015a3070dd17ULL, 0x152fecd8f70e5939ULL,
    0x67332667ffc00b31ULL, 0x8eb44a8768581511ULL,
    0xdb0c2e0d64f98fa7ULL, 0x47b5481dbefa4fa4ULL
};

static const uint64_t sha512_h0[8] = {
    0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL,
    0x3c6ef372fe94f82bULL, 0xa54ff53a5f1d36f1ULL,
    0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL,
    0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL
};

/*Precomputed sha2 shift columns and mix columns operations.*/
static const uint32_t sha256_k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static const uint64_t sha512_k[80] = {
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
    0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
    0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
    0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
    0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
    0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
    0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
    0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
    0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
    0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
    0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
    0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
    0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
    0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
    0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
    0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
    0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
    0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
    0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
    0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
    0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};

static __inline int sha224_init(Sha2Ctx *ctx)
{
    Sha224Ctx *ctx224;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);

    ctx224 = &ctx->type.ctx224;

    memset(ctx224->block, 0, SHA256_BLOCK_SIZE >> 1);
    memset(ctx224->h, 0, 32);

    BASE_INIT(ctx224, sha224_h0);
    ctx224->len = 0;
    ctx224->tot_len = 0;
    ctx->variant = SHA2_VARIANT_224;

cleanup:

    return ret;
}

static __inline int sha256_init(Sha2Ctx *ctx)
{
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    Sha256Ctx *ctx256 = &ctx->type.ctx256;

    memset(ctx256->block, 0, SHA256_BLOCK_SIZE >> 1);
    memset(ctx256->h, 0, 32);

    BASE_INIT(ctx256, sha256_h0);
    ctx256->len = 0;
    ctx256->tot_len = 0;
    ctx->variant = SHA2_VARIANT_256;

cleanup:

    return ret;
}

static __inline int sha384_init(Sha2Ctx *ctx)
{
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);

    Sha384Ctx *ctx384 = &ctx->type.ctx384;

    memset(ctx384->block, 0, SHA512_BLOCK_SIZE >> 1);
    memset(ctx384->h, 0, 64);
    BASE_INIT(ctx384, sha384_h0);
    ctx384->len = 0;
    ctx384->tot_len = 0;
    ctx->variant = SHA2_VARIANT_384;

cleanup:

    return ret;
}

static __inline int sha512_init(Sha2Ctx *ctx)
{
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);

    Sha512Ctx *ctx512 = &ctx->type.ctx512;

    memset(ctx512->block, 0, SHA512_BLOCK_SIZE >> 1);
    memset(ctx512->h, 0, 64);

    BASE_INIT(ctx512, sha512_h0);
    ctx512->len = 0;
    ctx512->tot_len = 0;
    ctx->variant = SHA2_VARIANT_512;

cleanup:

    return ret;
}

/* SHA-256 functions */
static __inline void sha256_transf(Sha256Ctx *ctx, const uint8_t *data, size_t block_len)
{
    uint32_t w[64];
    uint32_t wv[8];
    uint32_t t1, t2;
    const uint8_t *sub_block;
    int i;

    for (i = 0; i < (int) block_len; i++) {
        sub_block = data + (i << 6);
        PACK32(&sub_block[ 0], &w[0]);
        PACK32(&sub_block[ 4], &w[1]);
        PACK32(&sub_block[ 8], &w[2]);
        PACK32(&sub_block[ 12], &w[3]);
        PACK32(&sub_block[ 16], &w[4]);
        PACK32(&sub_block[ 20], &w[5]);
        PACK32(&sub_block[ 24], &w[6]);
        PACK32(&sub_block[ 28], &w[7]);
        PACK32(&sub_block[ 32], &w[8]);
        PACK32(&sub_block[ 36], &w[9]);
        PACK32(&sub_block[ 40], &w[10]);
        PACK32(&sub_block[ 44], &w[11]);
        PACK32(&sub_block[ 48], &w[12]);
        PACK32(&sub_block[ 52], &w[13]);
        PACK32(&sub_block[ 56], &w[14]);
        PACK32(&sub_block[ 60], &w[15]);

        SHA256_SCR_UNROLL(16);
        SHA256_SCR_UNROLL(24);
        SHA256_SCR_UNROLL(32);
        SHA256_SCR_UNROLL(40);
        SHA256_SCR_UNROLL(48);
        SHA256_SCR_UNROLL(56);

        wv[0] = ctx->h[0];
        wv[1] = ctx->h[1];
        wv[2] = ctx->h[2];
        wv[3] = ctx->h[3];
        wv[4] = ctx->h[4];
        wv[5] = ctx->h[5];
        wv[6] = ctx->h[6];
        wv[7] = ctx->h[7];

        SHA256_EXP_UNROLL(0);
        SHA256_EXP_UNROLL(8);
        SHA256_EXP_UNROLL(16);
        SHA256_EXP_UNROLL(24);
        SHA256_EXP_UNROLL(32);
        SHA256_EXP_UNROLL(40);
        SHA256_EXP_UNROLL(48);
        SHA256_EXP_UNROLL(56);

        ctx->h[0] += wv[0];
        ctx->h[1] += wv[1];
        ctx->h[2] += wv[2];
        ctx->h[3] += wv[3];
        ctx->h[4] += wv[4];
        ctx->h[5] += wv[5];
        ctx->h[6] += wv[6];
        ctx->h[7] += wv[7];
    }
}

/* SHA-512 functions */
static __inline void sha512_transf(Sha512Ctx *ctx, const uint8_t *msg, size_t block_nb)
{
    uint64_t w[80];
    uint64_t wv[8];
    uint64_t t1, t2;
    const uint8_t *sub_block;
    int i;

    for (i = 0; i < (int) block_nb; i++) {
        sub_block = msg + (i << 7);
        PACK64(&sub_block[ 0], &w[ 0]);
        PACK64(&sub_block[ 8], &w[ 1]);
        PACK64(&sub_block[ 16], &w[ 2]);
        PACK64(&sub_block[ 24], &w[ 3]);
        PACK64(&sub_block[ 32], &w[ 4]);
        PACK64(&sub_block[ 40], &w[ 5]);
        PACK64(&sub_block[ 48], &w[ 6]);
        PACK64(&sub_block[ 56], &w[ 7]);
        PACK64(&sub_block[ 64], &w[ 8]);
        PACK64(&sub_block[ 72], &w[ 9]);
        PACK64(&sub_block[ 80], &w[10]);
        PACK64(&sub_block[ 88], &w[11]);
        PACK64(&sub_block[ 96], &w[12]);
        PACK64(&sub_block[104], &w[13]);
        PACK64(&sub_block[112], &w[14]);
        PACK64(&sub_block[120], &w[15]);

        SHA512_SCR_UNROLL(16);
        SHA512_SCR_UNROLL(24);
        SHA512_SCR_UNROLL(32);
        SHA512_SCR_UNROLL(40);
        SHA512_SCR_UNROLL(48);
        SHA512_SCR_UNROLL(56);
        SHA512_SCR_UNROLL(64);
        SHA512_SCR_UNROLL(72);

        wv[0] = ctx->h[0];
        wv[1] = ctx->h[1];
        wv[2] = ctx->h[2];
        wv[3] = ctx->h[3];
        wv[4] = ctx->h[4];
        wv[5] = ctx->h[5];
        wv[6] = ctx->h[6];
        wv[7] = ctx->h[7];

        SHA512_EXP_UNROLL(0);
        SHA512_EXP_UNROLL(8);
        SHA512_EXP_UNROLL(16);
        SHA512_EXP_UNROLL(24);
        SHA512_EXP_UNROLL(32);
        SHA512_EXP_UNROLL(40);
        SHA512_EXP_UNROLL(48);
        SHA512_EXP_UNROLL(56);
        SHA512_EXP_UNROLL(64);
        SHA512_EXP_UNROLL(72);

        ctx->h[0] += wv[0];
        ctx->h[1] += wv[1];
        ctx->h[2] += wv[2];
        ctx->h[3] += wv[3];
        ctx->h[4] += wv[4];
        ctx->h[5] += wv[5];
        ctx->h[6] += wv[6];
        ctx->h[7] += wv[7];
    }
}

static int sha224_update(Sha224Ctx *ctx, const ByteArray *data_ba)
{
    uint8_t *shifted_message = NULL;
    uint8_t *data_buf = NULL;
    size_t msg_len;
    size_t block_nb;
    size_t new_len, rem_len, tmp_len;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(data_ba != NULL);

    data_buf = data_ba->buf;
    msg_len = data_ba->len;

    tmp_len = SHA224_BLOCK_SIZE - ctx->len;
    rem_len = msg_len < tmp_len ? msg_len : tmp_len;
    memcpy(&ctx->block[ctx->len], data_buf, rem_len);

    if (ctx->len + msg_len < SHA224_BLOCK_SIZE) {
        ctx->len += msg_len;
        ret = RET_OK;
        goto cleanup;
    }
    new_len = msg_len - rem_len;
    block_nb = new_len / SHA224_BLOCK_SIZE;
    shifted_message = data_buf + rem_len;

    sha256_transf(ctx, ctx->block, 1);
    memset(ctx->block, 0, SHA224_BLOCK_SIZE);
    if (ctx->len + msg_len != SHA224_BLOCK_SIZE) {
        sha256_transf(ctx, shifted_message, block_nb);
    }

    rem_len = new_len % SHA224_BLOCK_SIZE;
    memcpy(ctx->block, &shifted_message[block_nb << 6], rem_len);
    ctx->len = rem_len;
    ctx->tot_len += (block_nb + 1) << 6;

cleanup:

    return ret;
}

static int sha224_final(Sha2Ctx *ctx, ByteArray **hash_code)
{
    Sha224Ctx *ctx224;
    uint8_t digest[28];
    size_t block_nb;
    size_t pm_len;
    size_t len_b;
    ByteArray *ans = NULL;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(hash_code != NULL);

    ctx224 = &ctx->type.ctx224;
    if (ctx224 == NULL) {
        SET_ERROR(RET_INVALID_CTX);
    }

    memset(digest, 0, 28);
    block_nb = (1 + ((SHA224_BLOCK_SIZE - 9) < (ctx224->len % SHA224_BLOCK_SIZE)));
    len_b = (ctx224->tot_len + ctx224->len) << 3;
    pm_len = block_nb << 6;
    memset(ctx224->block + ctx224->len, 0, pm_len - ctx224->len);
    ctx224->block[ctx224->len] = 0x80;

    UNPACK32(len_b, ctx224->block + pm_len - 4);
    sha256_transf(ctx224, ctx224->block, block_nb);
    UNPACK32(ctx224->h[0], &digest[ 0]);
    UNPACK32(ctx224->h[1], &digest[ 4]);
    UNPACK32(ctx224->h[2], &digest[ 8]);
    UNPACK32(ctx224->h[3], &digest[12]);
    UNPACK32(ctx224->h[4], &digest[16]);
    UNPACK32(ctx224->h[5], &digest[20]);
    UNPACK32(ctx224->h[6], &digest[24]);

    CHECK_NOT_NULL(ans = ba_alloc_from_uint8(digest, 28));
    DO(sha224_init(ctx));

    *hash_code = ans;
    ans = NULL;

cleanup:

    ba_free(ans);

    return ret;
}

static int sha256_update(Sha256Ctx *ctx, const ByteArray *msg_ba)
{
    uint8_t *msg = NULL;
    uint8_t *shifted_msg = NULL;
    size_t msg_len;
    size_t block_nb;
    size_t new_len, rem_len, tmp_len;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(msg_ba != NULL);

    msg = msg_ba->buf;
    msg_len = msg_ba->len;

    tmp_len = SHA256_BLOCK_SIZE - ctx->len;
    rem_len = msg_len < tmp_len ? msg_len : tmp_len;
    memcpy(&ctx->block[ctx->len], msg, rem_len);

    if (ctx->len + msg_len < SHA256_BLOCK_SIZE) {
        ctx->len += msg_len;
        ret = RET_OK;
        goto cleanup;
    }
    new_len = msg_len - rem_len;
    block_nb = new_len / SHA256_BLOCK_SIZE;
    shifted_msg = msg + rem_len;

    sha256_transf(ctx, ctx->block, 1);
    sha256_transf(ctx, shifted_msg, block_nb);

    rem_len = new_len % SHA256_BLOCK_SIZE;
    memcpy(ctx->block, &shifted_msg[block_nb << 6], rem_len);
    ctx->len = rem_len;
    ctx->tot_len += (block_nb + 1) << 6;

cleanup:

    return ret;
}

static int sha256_final(Sha2Ctx *ctx, ByteArray **hash_code)
{
    Sha256Ctx *ctx256;
    uint8_t digest[32];
    size_t block_nb;
    size_t pm_len;
    size_t len_b;
    ByteArray *ans = NULL;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(hash_code != NULL);

    ctx256 = &ctx->type.ctx256;
    if (ctx256 == NULL) {
        SET_ERROR(RET_INVALID_CTX);
    }

    memset(digest, 0, 32);

    block_nb = (1 + ((SHA256_BLOCK_SIZE - 9) < (ctx256->len % SHA256_BLOCK_SIZE)));

    len_b = (ctx256->tot_len + ctx256->len) << 3;
    pm_len = block_nb << 6;

    memset(ctx256->block + ctx256->len, 0, pm_len - ctx256->len);
    ctx256->block[ctx256->len] = 0x80;
    UNPACK32(len_b, ctx256->block + pm_len - 4);

    sha256_transf(ctx256, ctx256->block, block_nb);

    UNPACK32(ctx256->h[0], &digest[ 0]);
    UNPACK32(ctx256->h[1], &digest[ 4]);
    UNPACK32(ctx256->h[2], &digest[ 8]);
    UNPACK32(ctx256->h[3], &digest[12]);
    UNPACK32(ctx256->h[4], &digest[16]);
    UNPACK32(ctx256->h[5], &digest[20]);
    UNPACK32(ctx256->h[6], &digest[24]);
    UNPACK32(ctx256->h[7], &digest[28]);

    CHECK_NOT_NULL(ans = ba_alloc_from_uint8(digest, SHA256_DIGEST_SIZE));
    DO(sha256_init(ctx));

    *hash_code = ans;
    ans = NULL;

cleanup:

    ba_free(ans);

    return ret;
}

static int sha384_update(Sha384Ctx *ctx, const ByteArray *msg_ba)
{
    uint8_t *shifted_message = NULL;
    uint8_t *msg = NULL;
    size_t block_nb;
    size_t new_len, rem_len, tmp_len;
    size_t msg_len;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(msg_ba->buf != NULL);

    msg = msg_ba->buf;
    msg_len = msg_ba->len;

    tmp_len = SHA384_BLOCK_SIZE - ctx->len;
    rem_len = msg_len < tmp_len ? msg_len : tmp_len;
    memcpy(&ctx->block[ctx->len], msg, rem_len);

    if (ctx->len + msg_len < SHA384_BLOCK_SIZE) {
        ctx->len += msg_len;
        ret = RET_OK;
        goto cleanup;
    }
    new_len = msg_len - rem_len;
    block_nb = new_len / SHA384_BLOCK_SIZE;
    shifted_message = msg + rem_len;

    sha512_transf(ctx, ctx->block, 1);
    sha512_transf(ctx, shifted_message, block_nb);

    rem_len = new_len % SHA384_BLOCK_SIZE;
    memcpy(ctx->block, &shifted_message[block_nb << 7], rem_len);
    ctx->len = rem_len;
    ctx->tot_len += (block_nb + 1) << 7;

cleanup:

    return ret;
}

static int sha384_final(Sha2Ctx *ctx, ByteArray **hash_code)
{
    Sha384Ctx *ctx384;
    uint8_t digest[48];
    size_t block_nb;
    size_t pm_len;
    size_t len_b;
    ByteArray *ans = NULL;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(hash_code != NULL);

    ctx384 = &ctx->type.ctx384;
    if (ctx384 == NULL) {
        SET_ERROR(RET_INVALID_CTX);
    }

    memset(digest, 0, 48);
    block_nb = (1 + ((SHA384_BLOCK_SIZE - 17) < (ctx384->len % SHA384_BLOCK_SIZE)));
    len_b = (ctx384->tot_len + ctx384->len) << 3;
    pm_len = block_nb << 7;
    memset(ctx384->block + ctx384->len, 0, pm_len - ctx384->len);
    ctx384->block[ctx384->len] = 0x80;

    UNPACK32(len_b, ctx384->block + pm_len - 4);
    sha512_transf(ctx384, ctx384->block, block_nb);
    UNPACK64(ctx384->h[0], &digest[ 0]);
    UNPACK64(ctx384->h[1], &digest[ 8]);
    UNPACK64(ctx384->h[2], &digest[16]);
    UNPACK64(ctx384->h[3], &digest[24]);
    UNPACK64(ctx384->h[4], &digest[32]);
    UNPACK64(ctx384->h[5], &digest[40]);

    CHECK_NOT_NULL(ans = ba_alloc_from_uint8(digest, SHA384_DIGEST_SIZE));
    DO(sha384_init(ctx));

    *hash_code = ans;
    ans = NULL;

cleanup:

    ba_free(ans);

    return ret;
}

static int sha512_update(Sha512Ctx *ctx, const ByteArray *msg_ba)
{
    uint8_t *shifted_message = NULL;
    uint8_t *msg = NULL;
    size_t msg_len;
    size_t block_nb;
    size_t new_len, rem_len, tmp_len;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(msg_ba != NULL);

    msg = msg_ba->buf;
    msg_len = msg_ba->len;

    tmp_len = SHA512_BLOCK_SIZE - ctx->len;
    rem_len = msg_len < tmp_len ? msg_len : tmp_len;
    memcpy(&ctx->block[ctx->len], msg, rem_len);

    if (ctx->len + msg_len < SHA512_BLOCK_SIZE) {
        ctx->len += msg_len;
        ret = RET_OK;
        goto cleanup;
    }

    new_len = msg_len - rem_len;
    block_nb = new_len / SHA512_BLOCK_SIZE;
    shifted_message = msg + rem_len;

    sha512_transf(ctx, ctx->block, 1);
    sha512_transf(ctx, shifted_message, block_nb);

    rem_len = new_len % SHA512_BLOCK_SIZE;
    memcpy(ctx->block, &shifted_message[block_nb << 7], rem_len);
    ctx->len = rem_len;
    ctx->tot_len += (block_nb + 1) << 7;

cleanup:

    return ret;
}

static int sha512_final(Sha2Ctx *ctx, ByteArray **hash_code)
{
    Sha512Ctx *ctx512;
    size_t block_nb;
    size_t pm_len;
    size_t len_b;
    uint8_t digest[64];
    ByteArray *ans = NULL;
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(hash_code != NULL);

    ctx512 = &ctx->type.ctx512;
    if (ctx512 == NULL) {
        SET_ERROR(RET_INVALID_CTX);
    }

    memset(digest, 0, 64);
    block_nb = 1 + ((SHA512_BLOCK_SIZE - 17) < (ctx512->len % SHA512_BLOCK_SIZE));
    len_b = (ctx512->tot_len + ctx512->len) << 3;
    pm_len = block_nb << 7;
    memset(ctx512->block + ctx512->len, 0, pm_len - ctx512->len);
    ctx512->block[ctx512->len] = 0x80;

    UNPACK32(len_b, ctx512->block + pm_len - 4);
    sha512_transf(ctx512, ctx512->block, block_nb);
    UNPACK64(ctx512->h[0], &digest[ 0]);
    UNPACK64(ctx512->h[1], &digest[ 8]);
    UNPACK64(ctx512->h[2], &digest[16]);
    UNPACK64(ctx512->h[3], &digest[24]);
    UNPACK64(ctx512->h[4], &digest[32]);
    UNPACK64(ctx512->h[5], &digest[40]);
    UNPACK64(ctx512->h[6], &digest[48]);
    UNPACK64(ctx512->h[7], &digest[56]);

    CHECK_NOT_NULL(ans = ba_alloc_from_uint8(digest, SHA512_DIGEST_SIZE));
    DO(sha512_init(ctx));

    *hash_code = ans;
    ans = NULL;

cleanup:

    ba_free(ans);

    return ret;
}

Sha2Ctx *sha2_alloc(Sha2Variant variant)
{
    int ret = RET_OK;
    Sha2Ctx *ctx = NULL;

    CALLOC_CHECKED(ctx, sizeof(Sha2Ctx));

    switch (variant) {
    case SHA2_VARIANT_224:
        DO(sha224_init(ctx));
        break;
    case SHA2_VARIANT_256:
        DO(sha256_init(ctx));
        break;
    case SHA2_VARIANT_384:
        DO(sha384_init(ctx));
        break;
    case SHA2_VARIANT_512:
        DO(sha512_init(ctx));
        break;
    default:
        SET_ERROR(RET_INVALID_PARAM);
    }

cleanup:

    if (ret != RET_OK) {
        sha2_free(ctx);
        ctx = NULL;
    }

    return ctx;
}

Sha2Ctx *sha2_copy_with_alloc(const Sha2Ctx *ctx)
{
    Sha2Ctx *out = NULL;
    int ret = RET_OK;

    CALLOC_CHECKED(out, sizeof(Sha2Ctx));
    memcpy(out, ctx, sizeof(Sha2Ctx));

cleanup:

    return out;
}

int sha2_update(Sha2Ctx *ctx, const ByteArray *data)
{
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(data != NULL);

    switch (ctx->variant) {
    case SHA2_VARIANT_224:
        DO(sha224_update(&ctx->type.ctx224, data));
        break;
    case SHA2_VARIANT_256:
        DO(sha256_update(&ctx->type.ctx256, data));
        break;
    case SHA2_VARIANT_384:
        DO(sha384_update(&ctx->type.ctx384, data));
        break;
    case SHA2_VARIANT_512:
        DO(sha512_update(&ctx->type.ctx512, data));
        break;
    default:
        SET_ERROR(RET_INVALID_CTX_MODE);
    }

cleanup:

    return ret;
}

int sha2_final(Sha2Ctx *ctx, ByteArray **out)
{
    int ret = RET_OK;

    CHECK_PARAM(ctx != NULL);
    CHECK_PARAM(out != NULL);

    switch (ctx->variant) {
    case SHA2_VARIANT_224:
        DO(sha224_final(ctx, out));
        break;
    case SHA2_VARIANT_256:
        DO(sha256_final(ctx, out));
        break;
    case SHA2_VARIANT_384:
        DO(sha384_final(ctx, out));
        break;
    case SHA2_VARIANT_512:
        DO(sha512_final(ctx, out));
        break;
    default:
        SET_ERROR(RET_INVALID_CTX_MODE);
    }

cleanup:

    return ret;
}

void sha2_free(Sha2Ctx *ctx)
{
    free(ctx);
}
