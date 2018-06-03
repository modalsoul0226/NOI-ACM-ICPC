#include <stdio.h>
#include <string.h>

int main() {
    char *keyboard = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'\\ZXCVBNM,./";
    int c = 0, i, len = strlen(keyboard);

    while ((c = getchar()) != EOF) {
        for (i = 1; i < len && keyboard[i] != c; i++);
        if (i < len) printf("%c", keyboard[i - 1]);
        else printf("%c", c);

    } 

    return 0;
}