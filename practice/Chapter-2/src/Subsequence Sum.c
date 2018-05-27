#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INT_MAX   2147483647
#define INT_MIN  -2147483648
#define LONG_MAX  2305843009213693951
#define LONG_MIN -2305843009213693952
#define MAX_NUM   1000000

/**
 * === IMPORTANT ===
 * PRECONDITION: n < m < 10^6 
 */
int main(int argc, char **argv)
{

#ifdef LOCAL
    freopen("../data_in/2_4_data.in", "r", stdin);
    freopen("../data_out/2_4_data.out", "w", stdout);
#endif
    // long n = pow((double)655360, (double)2); 
    // printf("Value of n: %ld\n", n);
    long n = 0, m = 0;
    int kase = 0;
    double sum = 0;

    while (scanf("%ld", &n)) 
    {
        scanf("%ld", &m);
        if (n == 0 && m == 0) break;

        while (n < MAX_NUM && n <= m) 
        {
           sum += pow(1.0 / n++, (double)2);
        }
        if (kase++) printf("\n");
        printf("Case %d: %.5f", kase, sum);
        sum = 0;
    }

    return 0;
}
