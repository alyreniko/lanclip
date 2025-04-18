#include "clipboard_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_wayland_session() {
    const char *session_type = getenv("XDG_SESSION_TYPE");
    return session_type && (strcmp(session_type, "wayland") == 0);
}

void get_clipboard(char *dest, size_t max_len) {
    const char *cmd = is_wayland_session() ? "wl-paste" : "xclip -selection clipboard -o";

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    if (fgets(dest, max_len, fp) == NULL) {
        perror("fgets");
    }

    if (pclose(fp) == -1) {
        perror("pclose");
    }
}

void set_clipboard(const char *text) {
    const char *session_type = getenv("XDG_SESSION_TYPE");
    const char *cmd = NULL;

    if (session_type && strcmp(session_type, "wayland") == 0) {
        cmd = "wl-copy";
    } else {
        cmd = "xclip -selection clipboard";
    }

    FILE *fp = popen(cmd, "w");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    if (fputs(text, fp) == EOF) {
        perror("fputs");
    }

    if (pclose(fp) == -1) {
        perror("pclose");
    }
}
