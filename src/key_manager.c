#include "key_manager.h"
#include <sodium.h>
#include <sodium/crypto_box.h>
#include <stdio.h>

int save_keys(const char *filename, const unsigned char *private_key, const unsigned char *public_key) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return -1;
    }

    size_t bytes_written = fwrite(private_key, 1, crypto_box_SECRETKEYBYTES, file);
    if (bytes_written != crypto_box_SECRETKEYBYTES) {
        fclose(file);
        fprintf(stderr, "Failed to write private key\n");
        return -1;
    }

    bytes_written = fwrite(public_key, 1, crypto_box_PUBLICKEYBYTES, file);
    if (bytes_written != crypto_box_PUBLICKEYBYTES) {
        fclose(file);
        fprintf(stderr, "Failed to write public key\n");
        return -1;
    }

    fclose(file);
    return 0;
}

int load_keys(const char *filename, unsigned char *private_key, unsigned char *public_key) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return -1;
    }

    size_t bytes_read = fread(private_key, 1, crypto_box_SECRETKEYBYTES, file);
    if (bytes_read != crypto_box_SECRETKEYBYTES) {
        fclose(file);
        fprintf(stderr, "Failed to read private key\n");
        return -1;
    }

    bytes_read = fread(public_key, 1, crypto_box_PUBLICKEYBYTES, file);
    if (bytes_read != crypto_box_PUBLICKEYBYTES) {
        fclose(file);
        fprintf(stderr, "Failed to read public key\n");
        return -1;
    }

    fclose(file);
    return 0;
}
