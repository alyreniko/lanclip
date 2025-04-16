#ifndef GET_LOCAL_HOSTNAME_H
#define GET_LOCAL_HOSTNAME_H

#include <stddef.h>

/*
 * get_local_hostname - Get the hostname of the current system.
 * @hostname: Buffer to store the hostname.
 * @size: Size of the buffer.
 * Return: 0 on success, -1 on failure.
 */
int get_local_hostname(
    char *hostname,
    const size_t size);

#endif
