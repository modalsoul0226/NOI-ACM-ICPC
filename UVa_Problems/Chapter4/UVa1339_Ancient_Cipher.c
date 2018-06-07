/** Implemented using qsort() from C's
 * standard library.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CODE_SIZE 101
#define ALPHA_SIZE 26


/**
 * The comparator function for qsort().
 * Return an integer less than, equal to,  or
 * greater  than  zero  if  the first argument 
 * is considered to be respectively less than, 
 * equal to, or greater than the second.
 */
int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int main() {
#ifdef LOCAL
    freopen("./UVa1339.fin", "r", stdin);    
#endif
    char code[CODE_SIZE]; memset(code, 0, sizeof(code));
    char text[CODE_SIZE]; memset(text, 0, sizeof(text));

    while (scanf("%s", code) != EOF) {
        scanf("%s", text);
        
        // Initialize the dictionary.
        int dict_c[ALPHA_SIZE]; memset(dict_c, 0, sizeof(dict_c));
        int dict_t[ALPHA_SIZE]; memset(dict_t, 0, sizeof(dict_t));
        for (int i = 0; i < strlen(code); i++) {
            dict_c[code[i] - 'A']++;
            dict_t[text[i] - 'A']++;
        }

        // Sort the dictionary according to the frequency.
        qsort(dict_c, ALPHA_SIZE, sizeof(int), cmp);
        qsort(dict_t, ALPHA_SIZE, sizeof(int), cmp);

        // Check whether the first line (code) can be the result of
        // the text after encrypting (substitution + permutation).
        int i;
        for (i = 0; i < ALPHA_SIZE; i++)
            if (dict_c[i] != dict_t[i]) { printf("NO\n"); break; }
        if (i == ALPHA_SIZE) printf("YES\n");
    }
}