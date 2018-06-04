#include <stdio.h>
#include <string.h>
#define MAX_LINE 101

int main() {

#ifdef LOCAL
    freopen("./UVa1584_fin", "r", stdin);
#endif
    int n = 0; scanf("%d", &n);

    char seq[MAX_LINE]; memset(seq, 0, sizeof(seq));
    for (int i = 0; i < n; i++) {
        scanf("%s", seq);

        int res = 0, len = strlen(seq);
        for (int j = 1; j < len; j++) {
            int k = 0;
            while (seq[(res + k) % len] == seq[(j + k) % len]) {
                if (k > len) break;
                k++;
            }
            res = seq[(res + k) % len] < seq[(j + k) % len] ? res : j;
        }

        for (int j = 0; j < len; j++) printf("%c", seq[(res + j) % len]);
        printf("\n");
    }

    return 0;
}