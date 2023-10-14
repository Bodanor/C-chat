#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int check_is_number(const char *string);
char *append_username(const char *username, const char *buffer);
#endif // __UTIL_H_
