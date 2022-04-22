#include <libchessviz/StrExtend.h>

int IsUpper(char c) {
    if (c == tolower(c))
        return -1;
    return 1;
}
int strfnd(char* dest, char val) {
    size_t i = 0;
    while (i < strlen(dest)) {
        if (dest[i] == val)
            return i;
        i++;
    }
    return -1;
}
