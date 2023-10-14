#include "util.h"

int check_is_number(const char *string)
{
    int i;

    for (i = 0; i < (int)strlen(string); i++) {
        if (isdigit(string[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

char *append_username(const char *username, const char *buffer)
{
    char *final_string;

    final_string = (char*)malloc(sizeof(char)*(strlen(username) + 4));
    if (final_string == NULL)
        return NULL;
    strcpy(final_string, username);
    strcat(final_string, " : ");

    final_string = (char*)realloc(final_string, strlen(final_string) + (strlen(buffer) + 1));
    if (final_string == NULL)
        return NULL;
    strcat(final_string, buffer);

    return final_string;

}
