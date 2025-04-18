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

/**
 * set_clipboard - Sets the contents of the clipboard.
 * @text: Pointer to the text to be set in the clipboard.
 *
 * This function sets the contents of the clipboard to the provided text.
 */
void set_clipboard(const char *text);

#endif
