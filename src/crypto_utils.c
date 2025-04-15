#include <sodium.h>
#include <stdio.h>
#include <string.h>

void encrypt_data(
    unsigned char *ciphertext,
    const unsigned char *plaintext,
    size_t plaintext_len,
    unsigned char nonce[crypto_secretbox_NONCEBYTES],
    const unsigned char key[crypto_secretbox_KEYBYTES]
) {
    randombytes_buf(nonce, crypto_secretbox_NONCEBYTES);
    if (crypto_secretbox_easy(ciphertext, plaintext, plaintext_len, nonce, key) != 0) {
        fprintf(stderr, "Encryption failed\n");
        return;
    }
}

void encrypt_key(unsigned char *ciphertext,
    const unsigned char *plaintext,
    unsigned char nonce[crypto_box_NONCEBYTES],
    const unsigned char foreign_public_key[crypto_box_PUBLICKEYBYTES],
    const unsigned char private_key[crypto_box_SECRETKEYBYTES]
) {
    randombytes_buf(nonce, crypto_box_NONCEBYTES);
    if (crypto_box_easy(ciphertext, plaintext, strlen(plaintext), nonce, foreign_public_key, private_key) != 0) {
        fprintf(stderr, "Encryption failed\n");
        return;
    };
}

void decrypt_data(
    unsigned char *decrypted,
    const unsigned char *ciphertext,
    const size_t ciphertext_len,
    const unsigned char nonce[crypto_secretbox_NONCEBYTES],
    const unsigned char key[crypto_secretbox_KEYBYTES]
) {
    if (crypto_secretbox_open_easy(decrypted, ciphertext, ciphertext_len, nonce, key) != 0) {
        fprintf(stderr, "Decryption failed\n");
        return;
    }
}

void decrypt_key(
    unsigned char *plaintext,
    const unsigned char *ciphertext,
    const unsigned char *nonce,
    const unsigned char foreign_public_key[crypto_box_PUBLICKEYBYTES],
    const unsigned char private_key[crypto_box_SECRETKEYBYTES]
) {
    if (crypto_box_open_easy(plaintext, ciphertext, crypto_box_MACBYTES + strlen(ciphertext), nonce, foreign_public_key, private_key) != 0) {
        fprintf(stderr, "Decryption failed\n");
        return;
    }
}
