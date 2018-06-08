// #include <stdio.h>
// #include <string.h>

// int readchar() {
//     for (;;) {
//         int ch = getchar();
//         if (ch != '\n' && ch != '\r') return ch;
//     }
// }

// int readint(int c) {
//     int v = 0;
//     while (c--) v = v * 2 + readchar() - '0';
//     return v;
// }

// int code[8][1 << 8];
// int readcodes() {
//     memset(code, 0, sizeof(code));
//     code[1][0] = readchar();
//     for (int len = 2; len <= 7; len++) {
//         for (int i = 0; i < (1 << len) - 1; i++) {
//             int ch = getchar();
//             if (ch == EOF) return 0;
//             if (ch == '\n' || ch == '\r') return 1;
//             code[len][i] = ch;
//         }
//     }
//     return 1;
// }

// int main() {
// #ifdef LOCAL
//     freopen("./UVa213.fin", "r", stdin);
// #endif

//     while (readcodes()) {
//         for (;;) {
//             int len = readint(3);
//             if (len == 0) break;
//             for (;;) {
//                 int v = readint(len);
//                 if (v == (1 << len) - 1) break;
//                 putchar(code[len][v]);
//             }
//         }
//         putchar('\n');
//     }
//     return 0;
// }

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
}

int read_char() {
    int n; do n = getchar();
    while (n == '\n' || n == '\r');

    return n;
}

/**
 * Read the header into encode table.
 */
int read_header() {
    // int n; while ((n = getchar()) == '\n');
    memset(encode_tab, 0, sizeof(encode_tab));
    encode_tab[1][0] = read_char();

    for (int i = 2; i < 8; i++) {
        int nmemb = (1 << i) - 1;
        // printf("size: %d\n", nmemb);

        for (int j = 0; j < nmemb; j++) {
            char temp = getchar();
            
            if (temp == '\n' || temp == '\r') return 1;
            else if (temp == EOF) return 0;
            else encode_tab[i][j] = temp;
        }
    }
}

/**
 * Convert the binary number with size chars 
 * to decimal.
 */
int read_num(int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        // Spins when encountering new line char.
        int n = read_char();
        res += (1 << (size - i - 1)) * (n - '0');
    }
    
    return res;
} 

int main() {
#ifdef LOCAL
    freopen("./UVa213.fin", "r", stdin);
#endif

    init_tab();

    while (read_header()) {

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