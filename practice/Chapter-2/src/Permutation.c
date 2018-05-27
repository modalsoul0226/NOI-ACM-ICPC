#include <stdio.h>
#include <string.h>

/**
 * A helper function dedicated to check whether
 * there are duplicate digits in a given number.
 * 
 * Return -1 if it contains duplicates, 0 if it does not.
 */
int check_duplicates(int num) 
{
    int d_table[9];
    memset(d_table, 0, sizeof(int) * 9);

    while (num) {
        int digit = num % 10;
        if (digit == 0) return -1;

        if (d_table[digit - 1]) return -1;
        else d_table[digit - 1] = 1;

        num /= 10;
    }

    return 0;
}

/**
 * Print every three numbers abc, def, ghi such that abc:def:ghi = 1:2:3
 * and every digit from 1 ~ 9 is used only once for abc, def and ghi.
 */
int main()
{   
    printf("Permutations: \n");

    for (int abc = 123; abc <= 329; abc++)
    {
        int def = abc * 2;
        int ghi = abc * 3;
        int sum = abc * 1e6 + def * 1e3 + ghi * 1e0;

        if (check_duplicates(sum)) continue;
        printf("%d %d %d\n", abc, def, ghi);
    }

    // double i;
    // for (i = 0; i < 10.0f; i += 0.1)
    //     printf("%.1f\n", i);
    return 0;
}

// #include<stdio.h>
// int main() {
//   int abc;
//   for(abc = 123; abc <= 329; abc++) {
//     int def = abc*2;
//     int ghi = abc*3;
//     int big = abc * 1000000 + def * 1000 + ghi;
//     int ok = 1, d;
//     for(d = 1; d <= 9; d++) {
//       int n = big;
//       int seen = 0;
//       while(n > 0) {
//         if(n % 10 == d) seen = 1;
//         n /= 10;
//       }
//       if(!seen) {
//         ok = 0; /* 数字d没有出现 */
//         break;
//       }
//     }
//     if(ok) printf("%d %d %d\n", abc, def, ghi);
//   }
//   return 0;
// }