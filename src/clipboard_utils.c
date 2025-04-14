#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_clipboard_wayland(char *dest, size_t max_len) {
    FILE *fp = popen("wl-paste", "r");
    if (fp == NULL) {
        return;
    }
    fgets(dest, max_len, fp);
    pclose(fp);
}
