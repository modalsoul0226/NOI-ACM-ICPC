#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 8 since the shortest code 
 * has length 1, and the longest
 * has length 7.
 */ 
char encode_tab[8][1 << 8];

/**
 * Initialize the encode table.
 */
void init_tab() {
    memset(encode_tab, 0, sizeof(encode_tab));
    // encode_tab[1][0] = getchar();
}


/**
 * Read the header into encode table.
 */
int read_header() {
    init_tab();

    int n; do n = getchar();
    while (n == '\n' || n == '\r');
    encode_tab[1][0] = n;

    for (int i = 2; i < 8; i++) {
        int nmemb = (1 << i) - 1;
        // printf("size: %d\n", nmemb);

        for (int j = 0; j < nmemb; j++) {
            char temp = getchar();
            
            if (temp == '\n' || temp == '\r') return 0;
            else if (temp == EOF) return 1;
            else encode_tab[i][j] = temp;
        }
    }

    return 0;
}

/**
 * Convert the binary number with size chars 
 * to decimal.
 */
int read_num(int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        // Spins when encountering new line char.
        int n;
        do n = getchar(); 
        while (n == '\n' || n == '\r');
        // while ((n = getchar()) == '\n');
        // printf("%c\n", n);
        // if (n != '1' && n != '0') {
        //     if (n == EOF) return -2;

        //     memset(encode_tab[1], 0, sizeof(encode_tab[1]));
        //     encode_tab[1][0] = n;
        //     return -1;
        // }
        // if (n == EOF) return -1;
        res += (1 << (size - i - 1)) * (n - '0');
    }
    
    return res;
} 

int main() {
#ifdef LOCAL
    freopen("./UVa213.fin", "r", stdin);
#endif

    init_tab();

    for (;;) {
        if (read_header()) break;
    #ifdef DEBUG
        printf("Header:\n");
        for (int i = 1; i < 8; i++)
            if (encode_tab[i]) {
                for (int j = 0; j < sizeof(encode_tab[i]); j++) {
                    printf("%c", encode_tab[i][j]);
                }
                printf("\n");
            }
    #endif

        int len = 0, res = 0;
        while ((len = read_num(3)) > 0) {
            // Decode the message segment.
            while ((res = read_num(len)) != (1 << len) - 1) {
                putchar(encode_tab[len][res]);
            }
        }
        putchar('\n');

        // char temp = getchar();
        // if (temp == EOF) break;

        // if (len == -1) break;
    }

    return 0;
}