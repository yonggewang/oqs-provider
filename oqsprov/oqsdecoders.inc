// SPDX-License-Identifier: Apache-2.0 AND MIT

/*
 * OQS OpenSSL 3 provider decoders
 *
 * Code strongly inspired by OpenSSL default provider.
 *
 */

#ifndef DECODER_PROVIDER
#    error Macro DECODER_PROVIDER undefined
#endif

#define DECODER_STRUCTURE_type_specific_keypair "type-specific"
#define DECODER_STRUCTURE_type_specific_params  "type-specific"
#define DECODER_STRUCTURE_type_specific         "type-specific"
#define DECODER_STRUCTURE_type_specific_no_pub  "type-specific"
#define DECODER_STRUCTURE_PKCS8                 "pkcs8"
#define DECODER_STRUCTURE_SubjectPublicKeyInfo  "SubjectPublicKeyInfo"
#define DECODER_STRUCTURE_PrivateKeyInfo        "PrivateKeyInfo"

/* Arguments are prefixed with '_' to avoid build breaks on certain platforms */
#define DECODER(_name, _input, _output)                        \
    {                                                          \
        _name, "provider=" DECODER_PROVIDER ",input=" #_input, \
            (oqs_##_input##_to_##_output##_decoder_functions)  \
    }
#define DECODER_w_structure(_name, _input, _structure, _output)              \
    {                                                                        \
        _name,                                                               \
            "provider=" DECODER_PROVIDER ",input=" #_input                   \
            ",structure=" DECODER_STRUCTURE_##_structure,                    \
            (oqs_##_structure##_##_input##_to_##_output##_decoder_functions) \
    }

///// OQS_TEMPLATE_FRAGMENT_MAKE_START
#ifdef OQS_KEM_ENCODERS

#    ifdef OQS_ENABLE_KEM_frodokem_640_aes
DECODER_w_structure("frodo640aes", der, PrivateKeyInfo, frodo640aes),
    DECODER_w_structure("frodo640aes", der, SubjectPublicKeyInfo, frodo640aes),
    DECODER_w_structure("p256_frodo640aes", der, PrivateKeyInfo,
                        p256_frodo640aes),
    DECODER_w_structure("p256_frodo640aes", der, SubjectPublicKeyInfo,
                        p256_frodo640aes),
    DECODER_w_structure("x25519_frodo640aes", der, PrivateKeyInfo,
                        x25519_frodo640aes),
    DECODER_w_structure("x25519_frodo640aes", der, SubjectPublicKeyInfo,
                        x25519_frodo640aes),
#    endif
#    ifdef OQS_ENABLE_KEM_frodokem_640_shake
    DECODER_w_structure("frodo640shake", der, PrivateKeyInfo, frodo640shake),
    DECODER_w_structure("frodo640shake", der, SubjectPublicKeyInfo,
                        frodo640shake),
    DECODER_w_structure("p256_frodo640shake", der, PrivateKeyInfo,
                        p256_frodo640shake),
    DECODER_w_structure("p256_frodo640shake", der, SubjectPublicKeyInfo,
                        p256_frodo640shake),
    DECODER_w_structure("x25519_frodo640shake", der, PrivateKeyInfo,
                        x25519_frodo640shake),
    DECODER_w_structure("x25519_frodo640shake", der, SubjectPublicKeyInfo,
                        x25519_frodo640shake),
#    endif
#    ifdef OQS_ENABLE_KEM_frodokem_976_aes
    DECODER_w_structure("frodo976aes", der, PrivateKeyInfo, frodo976aes),
    DECODER_w_structure("frodo976aes", der, SubjectPublicKeyInfo, frodo976aes),
    DECODER_w_structure("p384_frodo976aes", der, PrivateKeyInfo,
                        p384_frodo976aes),
    DECODER_w_structure("p384_frodo976aes", der, SubjectPublicKeyInfo,
                        p384_frodo976aes),
    DECODER_w_structure("x448_frodo976aes", der, PrivateKeyInfo,
                        x448_frodo976aes),
    DECODER_w_structure("x448_frodo976aes", der, SubjectPublicKeyInfo,
                        x448_frodo976aes),
#    endif
#    ifdef OQS_ENABLE_KEM_frodokem_976_shake
    DECODER_w_structure("frodo976shake", der, PrivateKeyInfo, frodo976shake),
    DECODER_w_structure("frodo976shake", der, SubjectPublicKeyInfo,
                        frodo976shake),
    DECODER_w_structure("p384_frodo976shake", der, PrivateKeyInfo,
                        p384_frodo976shake),
    DECODER_w_structure("p384_frodo976shake", der, SubjectPublicKeyInfo,
                        p384_frodo976shake),
    DECODER_w_structure("x448_frodo976shake", der, PrivateKeyInfo,
                        x448_frodo976shake),
    DECODER_w_structure("x448_frodo976shake", der, SubjectPublicKeyInfo,
                        x448_frodo976shake),
#    endif
#    ifdef OQS_ENABLE_KEM_frodokem_1344_aes
    DECODER_w_structure("frodo1344aes", der, PrivateKeyInfo, frodo1344aes),
    DECODER_w_structure("frodo1344aes", der, SubjectPublicKeyInfo,
                        frodo1344aes),
    DECODER_w_structure("p521_frodo1344aes", der, PrivateKeyInfo,
                        p521_frodo1344aes),
    DECODER_w_structure("p521_frodo1344aes", der, SubjectPublicKeyInfo,
                        p521_frodo1344aes),
#    endif
#    ifdef OQS_ENABLE_KEM_frodokem_1344_shake
    DECODER_w_structure("frodo1344shake", der, PrivateKeyInfo, frodo1344shake),
    DECODER_w_structure("frodo1344shake", der, SubjectPublicKeyInfo,
                        frodo1344shake),
    DECODER_w_structure("p521_frodo1344shake", der, PrivateKeyInfo,
                        p521_frodo1344shake),
    DECODER_w_structure("p521_frodo1344shake", der, SubjectPublicKeyInfo,
                        p521_frodo1344shake),
#    endif
#    ifdef OQS_ENABLE_KEM_kyber_512
    DECODER_w_structure("kyber512", der, PrivateKeyInfo, kyber512),
    DECODER_w_structure("kyber512", der, SubjectPublicKeyInfo, kyber512),
    DECODER_w_structure("p256_kyber512", der, PrivateKeyInfo, p256_kyber512),
    DECODER_w_structure("p256_kyber512", der, SubjectPublicKeyInfo,
                        p256_kyber512),
    DECODER_w_structure("x25519_kyber512", der, PrivateKeyInfo,
                        x25519_kyber512),
    DECODER_w_structure("x25519_kyber512", der, SubjectPublicKeyInfo,
                        x25519_kyber512),
#    endif
#    ifdef OQS_ENABLE_KEM_rlce_l1
    DECODER_w_structure("rlcel1", der, PrivateKeyInfo, rlcel1),
    DECODER_w_structure("rlcel1", der, SubjectPublicKeyInfo, rlcel1),
#    endif
#    ifdef OQS_ENABLE_KEM_rlce_l3
    DECODER_w_structure("rlcel3", der, PrivateKeyInfo, rlcel3),
    DECODER_w_structure("rlcel3", der, SubjectPublicKeyInfo, rlcel3),
#    endif
#    ifdef OQS_ENABLE_KEM_rlce_l5
    DECODER_w_structure("rlcel5", der, PrivateKeyInfo, rlcel5),
    DECODER_w_structure("rlcel5", der, SubjectPublicKeyInfo, rlcel5),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_348864
    DECODER_w_structure("classicmceliece348864", der, PrivateKeyInfo, classicmceliece348864),
    DECODER_w_structure("classicmceliece348864", der, SubjectPublicKeyInfo, classicmceliece348864),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_348864f
    DECODER_w_structure("classicmceliece348864f", der, PrivateKeyInfo, classicmceliece348864f),
    DECODER_w_structure("classicmceliece348864f", der, SubjectPublicKeyInfo, classicmceliece348864f),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_460896
    DECODER_w_structure("classicmceliece460896", der, PrivateKeyInfo, classicmceliece460896),
    DECODER_w_structure("classicmceliece460896", der, SubjectPublicKeyInfo, classicmceliece460896),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_460896f
    DECODER_w_structure("classicmceliece460896f", der, PrivateKeyInfo, classicmceliece460896f),
    DECODER_w_structure("classicmceliece460896f", der, SubjectPublicKeyInfo, classicmceliece460896f),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_6688128
    DECODER_w_structure("classicmceliece6688128", der, PrivateKeyInfo, classicmceliece6688128),
    DECODER_w_structure("classicmceliece6688128", der, SubjectPublicKeyInfo, classicmceliece6688128),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_6688128f
    DECODER_w_structure("classicmceliece6688128f", der, PrivateKeyInfo, classicmceliece6688128f),
    DECODER_w_structure("classicmceliece6688128f", der, SubjectPublicKeyInfo, classicmceliece6688128f),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_6960119
    DECODER_w_structure("classicmceliece6960119", der, PrivateKeyInfo, classicmceliece6960119),
    DECODER_w_structure("classicmceliece6960119", der, SubjectPublicKeyInfo, classicmceliece6960119),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_6960119f
    DECODER_w_structure("classicmceliece6960119f", der, PrivateKeyInfo, classicmceliece6960119f),
    DECODER_w_structure("classicmceliece6960119f", der, SubjectPublicKeyInfo, classicmceliece6960119f),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_8192128
    DECODER_w_structure("classicmceliece8192128", der, PrivateKeyInfo, classicmceliece8192128),
    DECODER_w_structure("classicmceliece8192128", der, SubjectPublicKeyInfo, classicmceliece8192128),
#    endif
#    ifdef OQS_ENABLE_KEM_classic_mceliece_8192128f
    DECODER_w_structure("classicmceliece8192128f", der, PrivateKeyInfo, classicmceliece8192128f),
    DECODER_w_structure("classicmceliece8192128f", der, SubjectPublicKeyInfo, classicmceliece8192128f),
#    endif
#    ifdef OQS_ENABLE_KEM_kyber_768
    DECODER_w_structure("kyber768", der, PrivateKeyInfo, kyber768),
    DECODER_w_structure("kyber768", der, SubjectPublicKeyInfo, kyber768),
    DECODER_w_structure("p384_kyber768", der, PrivateKeyInfo, p384_kyber768),
    DECODER_w_structure("p384_kyber768", der, SubjectPublicKeyInfo,
                        p384_kyber768),
    DECODER_w_structure("x448_kyber768", der, PrivateKeyInfo, x448_kyber768),
    DECODER_w_structure("x448_kyber768", der, SubjectPublicKeyInfo,
                        x448_kyber768),
    DECODER_w_structure("x25519_kyber768", der, PrivateKeyInfo,
                        x25519_kyber768),
    DECODER_w_structure("x25519_kyber768", der, SubjectPublicKeyInfo,
                        x25519_kyber768),
    DECODER_w_structure("p256_kyber768", der, PrivateKeyInfo, p256_kyber768),
    DECODER_w_structure("p256_kyber768", der, SubjectPublicKeyInfo,
                        p256_kyber768),
#    endif
#    ifdef OQS_ENABLE_KEM_kyber_1024
    DECODER_w_structure("kyber1024", der, PrivateKeyInfo, kyber1024),
    DECODER_w_structure("kyber1024", der, SubjectPublicKeyInfo, kyber1024),
    DECODER_w_structure("p521_kyber1024", der, PrivateKeyInfo, p521_kyber1024),
    DECODER_w_structure("p521_kyber1024", der, SubjectPublicKeyInfo,
                        p521_kyber1024),
#    endif
#    ifdef OQS_ENABLE_KEM_bike_l1
    DECODER_w_structure("bikel1", der, PrivateKeyInfo, bikel1),
    DECODER_w_structure("bikel1", der, SubjectPublicKeyInfo, bikel1),
    DECODER_w_structure("p256_bikel1", der, PrivateKeyInfo, p256_bikel1),
    DECODER_w_structure("p256_bikel1", der, SubjectPublicKeyInfo, p256_bikel1),
    DECODER_w_structure("x25519_bikel1", der, PrivateKeyInfo, x25519_bikel1),
    DECODER_w_structure("x25519_bikel1", der, SubjectPublicKeyInfo,
                        x25519_bikel1),
#    endif
#    ifdef OQS_ENABLE_KEM_bike_l3
    DECODER_w_structure("bikel3", der, PrivateKeyInfo, bikel3),
    DECODER_w_structure("bikel3", der, SubjectPublicKeyInfo, bikel3),
    DECODER_w_structure("p384_bikel3", der, PrivateKeyInfo, p384_bikel3),
    DECODER_w_structure("p384_bikel3", der, SubjectPublicKeyInfo, p384_bikel3),
    DECODER_w_structure("x448_bikel3", der, PrivateKeyInfo, x448_bikel3),
    DECODER_w_structure("x448_bikel3", der, SubjectPublicKeyInfo, x448_bikel3),
#    endif
#    ifdef OQS_ENABLE_KEM_bike_l5
    DECODER_w_structure("bikel5", der, PrivateKeyInfo, bikel5),
    DECODER_w_structure("bikel5", der, SubjectPublicKeyInfo, bikel5),
    DECODER_w_structure("p521_bikel5", der, PrivateKeyInfo, p521_bikel5),
    DECODER_w_structure("p521_bikel5", der, SubjectPublicKeyInfo, p521_bikel5),
#    endif
#    ifdef OQS_ENABLE_KEM_hqc_128
    DECODER_w_structure("hqc128", der, PrivateKeyInfo, hqc128),
    DECODER_w_structure("hqc128", der, SubjectPublicKeyInfo, hqc128),
    DECODER_w_structure("p256_hqc128", der, PrivateKeyInfo, p256_hqc128),
    DECODER_w_structure("p256_hqc128", der, SubjectPublicKeyInfo, p256_hqc128),
    DECODER_w_structure("x25519_hqc128", der, PrivateKeyInfo, x25519_hqc128),
    DECODER_w_structure("x25519_hqc128", der, SubjectPublicKeyInfo,
                        x25519_hqc128),
#    endif
#    ifdef OQS_ENABLE_KEM_hqc_192
    DECODER_w_structure("hqc192", der, PrivateKeyInfo, hqc192),
    DECODER_w_structure("hqc192", der, SubjectPublicKeyInfo, hqc192),
    DECODER_w_structure("p384_hqc192", der, PrivateKeyInfo, p384_hqc192),
    DECODER_w_structure("p384_hqc192", der, SubjectPublicKeyInfo, p384_hqc192),
    DECODER_w_structure("x448_hqc192", der, PrivateKeyInfo, x448_hqc192),
    DECODER_w_structure("x448_hqc192", der, SubjectPublicKeyInfo, x448_hqc192),
#    endif
#    ifdef OQS_ENABLE_KEM_hqc_256
    DECODER_w_structure("hqc256", der, PrivateKeyInfo, hqc256),
    DECODER_w_structure("hqc256", der, SubjectPublicKeyInfo, hqc256),
    DECODER_w_structure("p521_hqc256", der, PrivateKeyInfo, p521_hqc256),
    DECODER_w_structure("p521_hqc256", der, SubjectPublicKeyInfo, p521_hqc256),
#    endif

#endif /* OQS_KEM_ENCODERS */

#ifdef OQS_ENABLE_SIG_dilithium_2
    DECODER_w_structure("dilithium2", der, PrivateKeyInfo, dilithium2),
    DECODER_w_structure("dilithium2", der, SubjectPublicKeyInfo, dilithium2),
    DECODER_w_structure("p256_dilithium2", der, PrivateKeyInfo,
                        p256_dilithium2),
    DECODER_w_structure("p256_dilithium2", der, SubjectPublicKeyInfo,
                        p256_dilithium2),
    DECODER_w_structure("rsa3072_dilithium2", der, PrivateKeyInfo,
                        rsa3072_dilithium2),
    DECODER_w_structure("rsa3072_dilithium2", der, SubjectPublicKeyInfo,
                        rsa3072_dilithium2),
#endif
#ifdef OQS_ENABLE_SIG_dilithium_3
    DECODER_w_structure("dilithium3", der, PrivateKeyInfo, dilithium3),
    DECODER_w_structure("dilithium3", der, SubjectPublicKeyInfo, dilithium3),
    DECODER_w_structure("p384_dilithium3", der, PrivateKeyInfo,
                        p384_dilithium3),
    DECODER_w_structure("p384_dilithium3", der, SubjectPublicKeyInfo,
                        p384_dilithium3),
#endif
#ifdef OQS_ENABLE_SIG_dilithium_5
    DECODER_w_structure("dilithium5", der, PrivateKeyInfo, dilithium5),
    DECODER_w_structure("dilithium5", der, SubjectPublicKeyInfo, dilithium5),
    DECODER_w_structure("p521_dilithium5", der, PrivateKeyInfo,
                        p521_dilithium5),
    DECODER_w_structure("p521_dilithium5", der, SubjectPublicKeyInfo,
                        p521_dilithium5),
#endif
#ifdef OQS_ENABLE_SIG_falcon_512
    DECODER_w_structure("falcon512", der, PrivateKeyInfo, falcon512),
    DECODER_w_structure("falcon512", der, SubjectPublicKeyInfo, falcon512),
    DECODER_w_structure("p256_falcon512", der, PrivateKeyInfo, p256_falcon512),
    DECODER_w_structure("p256_falcon512", der, SubjectPublicKeyInfo,
                        p256_falcon512),
    DECODER_w_structure("rsa3072_falcon512", der, PrivateKeyInfo,
                        rsa3072_falcon512),
    DECODER_w_structure("rsa3072_falcon512", der, SubjectPublicKeyInfo,
                        rsa3072_falcon512),
#endif
#ifdef OQS_ENABLE_SIG_falcon_1024
    DECODER_w_structure("falcon1024", der, PrivateKeyInfo, falcon1024),
    DECODER_w_structure("falcon1024", der, SubjectPublicKeyInfo, falcon1024),
    DECODER_w_structure("p521_falcon1024", der, PrivateKeyInfo,
                        p521_falcon1024),
    DECODER_w_structure("p521_falcon1024", der, SubjectPublicKeyInfo,
                        p521_falcon1024),
#endif
#ifdef OQS_ENABLE_SIG_sphincs_sha2_128f_simple
    DECODER_w_structure("sphincssha2128fsimple", der, PrivateKeyInfo,
                        sphincssha2128fsimple),
    DECODER_w_structure("sphincssha2128fsimple", der, SubjectPublicKeyInfo,
                        sphincssha2128fsimple),
    DECODER_w_structure("p256_sphincssha2128fsimple", der, PrivateKeyInfo,
                        p256_sphincssha2128fsimple),
    DECODER_w_structure("p256_sphincssha2128fsimple", der, SubjectPublicKeyInfo,
                        p256_sphincssha2128fsimple),
    DECODER_w_structure("rsa3072_sphincssha2128fsimple", der, PrivateKeyInfo,
                        rsa3072_sphincssha2128fsimple),
    DECODER_w_structure("rsa3072_sphincssha2128fsimple", der,
                        SubjectPublicKeyInfo, rsa3072_sphincssha2128fsimple),
#endif
#ifdef OQS_ENABLE_SIG_sphincs_sha2_128s_simple
    DECODER_w_structure("sphincssha2128ssimple", der, PrivateKeyInfo,
                        sphincssha2128ssimple),
    DECODER_w_structure("sphincssha2128ssimple", der, SubjectPublicKeyInfo,
                        sphincssha2128ssimple),
    DECODER_w_structure("p256_sphincssha2128ssimple", der, PrivateKeyInfo,
                        p256_sphincssha2128ssimple),
    DECODER_w_structure("p256_sphincssha2128ssimple", der, SubjectPublicKeyInfo,
                        p256_sphincssha2128ssimple),
    DECODER_w_structure("rsa3072_sphincssha2128ssimple", der, PrivateKeyInfo,
                        rsa3072_sphincssha2128ssimple),
    DECODER_w_structure("rsa3072_sphincssha2128ssimple", der,
                        SubjectPublicKeyInfo, rsa3072_sphincssha2128ssimple),
#endif
#ifdef OQS_ENABLE_SIG_sphincs_sha2_192f_simple
    DECODER_w_structure("sphincssha2192fsimple", der, PrivateKeyInfo,
                        sphincssha2192fsimple),
    DECODER_w_structure("sphincssha2192fsimple", der, SubjectPublicKeyInfo,
                        sphincssha2192fsimple),
    DECODER_w_structure("p384_sphincssha2192fsimple", der, PrivateKeyInfo,
                        p384_sphincssha2192fsimple),
    DECODER_w_structure("p384_sphincssha2192fsimple", der, SubjectPublicKeyInfo,
                        p384_sphincssha2192fsimple),
#endif
#ifdef OQS_ENABLE_SIG_sphincs_shake_128f_simple
    DECODER_w_structure("sphincsshake128fsimple", der, PrivateKeyInfo,
                        sphincsshake128fsimple),
    DECODER_w_structure("sphincsshake128fsimple", der, SubjectPublicKeyInfo,
                        sphincsshake128fsimple),
    DECODER_w_structure("p256_sphincsshake128fsimple", der, PrivateKeyInfo,
                        p256_sphincsshake128fsimple),
    DECODER_w_structure("p256_sphincsshake128fsimple", der,
                        SubjectPublicKeyInfo, p256_sphincsshake128fsimple),
    DECODER_w_structure("rsa3072_sphincsshake128fsimple", der, PrivateKeyInfo,
                        rsa3072_sphincsshake128fsimple),
    DECODER_w_structure("rsa3072_sphincsshake128fsimple", der,
                        SubjectPublicKeyInfo, rsa3072_sphincsshake128fsimple),
#endif
    ///// OQS_TEMPLATE_FRAGMENT_MAKE_END
