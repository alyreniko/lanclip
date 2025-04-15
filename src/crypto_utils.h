#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <sodium.h>

/**
 * Encrypts data using secret-key encryption.
 * @param ciphertext Output buffer for the encrypted data
 * @param plaintext Input buffer containing the data to encrypt
 * @param plaintext_len Length of the plaintext buffer in bytes
 * @param nonce Unique nonce used for encryption (should never be reused)
 * @param key Secret key used for encryption
 */
void encrypt_data(
    unsigned char *ciphertext,
    const unsigned char *plaintext,
    size_t plaintext_len,
    unsigned char nonce[crypto_secretbox_NONCEBYTES],
    const unsigned char key[crypto_secretbox_KEYBYTES]);

/**
 * Encrypts a key using public-key encryption.
 * @param ciphertext Output buffer for the encrypted key
 * @param plaintext Input buffer containing the key to encrypt
 * @param nonce Unique nonce used for encryption (should never be reused)
 * @param foreign_public_key Public key of the recipient
 * @param private_key Private key of the sender
 */
void encrypt_key(
    unsigned char *ciphertext,
    const unsigned char *plaintext,
    unsigned char nonce[crypto_box_NONCEBYTES],
    const unsigned char foreign_public_key[crypto_box_PUBLICKEYBYTES],
    const unsigned char private_key[crypto_box_SECRETKEYBYTES]);

/**
 * Decrypts data that was previously encrypted with encrypt_data.
 * @param decrypted Output buffer for the decrypted plaintext
 * @param ciphertext Input buffer containing the encrypted data
 * @param ciphertext_len Length of the ciphertext buffer in bytes
 * @param nonce Unique nonce that was used for encryption
 * @param key Secret key that was used for encryption
 */
void decrypt_data(
    unsigned char *decrypted,
    const unsigned char *ciphertext,
    const size_t ciphertext_len,
    const unsigned char nonce[crypto_secretbox_NONCEBYTES],
    const unsigned char key[crypto_secretbox_KEYBYTES]);

/**
 * Decrypts a key that was previously encrypted with encrypt_key.
 * @param plaintext Output buffer for the decrypted key
 * @param ciphertext Input buffer containing the encrypted key
 * @param nonce Unique nonce that was used for encryption
 * @param foreign_public_key Public key of the sender
 * @param private_key Private key of the recipient
 */
void decrypt_key(
    unsigned char *plaintext,
    const unsigned char *ciphertext,
    const unsigned char *nonce,
    const unsigned char foreign_public_key[crypto_box_PUBLICKEYBYTES],
    const unsigned char private_key[crypto_box_SECRETKEYBYTES]);

#endif
