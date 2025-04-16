#ifndef HOSTNAME_H
#define HOSTNAME_H

#include <stddef.h>

/*
 * get_hostname - Get the hostname of the current system.
 * @hostname: Buffer to store the hostname.
 * @size: Size of the buffer.
 * Return: 0 on success, -1 on failure.
 */
int get_hostname(
    char *hostname,
    const size_t size);

#endif
