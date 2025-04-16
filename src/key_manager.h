#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H

#include <sodium.h>

/*
 * Save keypair to a file.
 * @param filename The name of the file to save the keys to.
 * @param private_key The private key to save.
 * @param public_key The public key to save.
 * @return 0 on success, -1 on failure.
 */
int save_keypair(
    const char *filename,
    const unsigned char *private_key,
    const unsigned char *public_key);

/*
 * Load keypair from a file.
 * @param filename The name of the file to load the keys from.
 * @param private_key The buffer to store the private key in.
 * @param public_key The buffer to store the public key in.
 * @return 0 on success, -1 on failure.
 */
int load_keypair(
    const char *filename,
    unsigned char *private_key,
    unsigned char *public_key);

#endif
