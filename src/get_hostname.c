#include "get_hostname.h"
#include <stdio.h>
#include <unistd.h>

int get_hostname(char *hostname, size_t size) {
    if (gethostname(hostname, size) != 0) {
        fprintf(stderr, "Error getting hostname\n");
        return -1;
    }
    return 0;
}
