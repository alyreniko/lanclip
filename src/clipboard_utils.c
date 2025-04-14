#include "clipboard_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_clipboard(char *dest, size_t max_len) {
    const char *session_type = getenv("XDG_SESSION_TYPE");
    const char *cmd = NULL;

    if (session_type && strcmp(session_type, "wayland") == 0) {
        cmd = "wl-paste";
    } else {
        cmd = "xclip -selection clipboard -o";
    }

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        return;
    }

    fgets(dest, max_len, fp);
    pclose(fp);
}
