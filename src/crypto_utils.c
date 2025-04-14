#include <sodium.h>
#include <sodium/crypto_secretbox.h>
#include <stdio.h>
#include <string.h>

void encrypt_data(const unsigned char *plaintext,
    unsigned char *ciphertext,
    unsigned char nonce[crypto_secretbox_NONCEBYTES],
    const unsigned char key[crypto_secretbox_KEYBYTES]
) {
    randombytes_buf(nonce, crypto_secretbox_NONCEBYTES);
    if (crypto_secretbox_easy(ciphertext, plaintext, strlen(plaintext), nonce, key) != 0) {
        fprintf(stderr, "Encryption failed\n");
        return;
    };
}

void decrypt_data(const unsigned char *ciphertext,
    unsigned char *plaintext,
    const unsigned char *nonce,
    const unsigned char key[crypto_secretbox_KEYBYTES]
) {
    if (crypto_secretbox_open_easy(plaintext, ciphertext, crypto_secretbox_MACBYTES + strlen(ciphertext), nonce, key) != 0) {
        fprintf(stderr, "Decryption failed\n");
        return;
    }
}
