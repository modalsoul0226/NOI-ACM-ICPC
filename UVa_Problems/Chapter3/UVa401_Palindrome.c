#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main() {
    char buf[MAX_LEN]; memset(buf, 0, sizeof(buf));
    char *alph_tab = "A   3  HIL JM O   2TUVWXY5"; char *d_tab = "1SE Z  8 ";

    while (fgets(buf, MAX_LEN, stdin)) {
        int end = buf[strlen(buf) - 1] == '\n' ? strlen(buf) - 2 : strlen(buf) - 1;
        buf[end + 1] = '\0';
        int start = 0, m = 1, p = 1;

        while (start <= end) {
            if ('A' <= buf[start] && buf[start] <= 'Z')
                { if (alph_tab[buf[start] - 'A'] != buf[end]) m = 0; }
            else
                { if (d_tab[buf[start] - '1'] != buf[end]) m = 0; }
            
            if (buf[start++] != buf[end--]) p = 0;
        }
        
        if (!p && !m) printf("%s -- is not a palindrome.\n\n", buf);
        else if (p && m) printf("%s -- is a mirrored palindrome.\n\n", buf);
        else if (p) printf("%s -- is a regular palindrome.\n\n", buf);
        else printf("%s -- is a mirrored string.\n\n", buf);
    }
}