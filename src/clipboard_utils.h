#ifndef CLIPBOARD_UTILS_H
#define CLIPBOARD_UTILS_H

#include <stddef.h>

/**
 * get_clipboard - Retrieves the contents of the clipboard.
 * @dest: Pointer to the destination buffer.
 * @max_len: Maximum length of the destination buffer.
 *
 * This function retrieves the contents of the clipboard and stores them in the
 * provided destination buffer. The maximum length of the buffer is specified by
 * @max_len. If the clipboard content is longer than @max_len, it will be truncated.
 */
void get_clipboard(char *dest, size_t max_len);

#endif
