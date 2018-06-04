#include <stdio.h>
#include <string.h>
#define MAX_N 100001
#define INF   1e5

int main() {
    int table[MAX_N]; memset(table, 0, sizeof(table));
    for (int i = 1; i < MAX_N; i++) {
        int temp = i, index = temp;
        while (temp) {
            index += temp % 10;
            temp /= 10;
        }

        if (index <= INF && !table[index]) table[index] = i;
    }

    int t = 0, n = 0; scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", table[n]);
    }
}

// TLE Version
// int main() {
//     int t = 0, n = 0; scanf("%d", &t);
//     for (int i = 0; i < t; i++) {
//         scanf("%d", &n); int res = 0;

//         int j;
//         for (j = 0; j < n; j++) {
//             int temp = j, sum = temp;
//             while (temp) { sum += temp % 10; temp /= 10; }
//             if (sum == n) {
//                 printf("%d\n", j);
//                 break;
//             }
//         }
//         if (j == n) printf("0\n");
//     }
// }
