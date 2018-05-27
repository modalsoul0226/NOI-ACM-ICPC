#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{

#ifdef LOCAL
    freopen("../data_in/2_5_data.in", "r", stdin);
    freopen("../data_out/2_5_data.out", "w", stdout);
#endif

    double a = 0, b = 0;
    int c = 0, kase = 0;

    while (scanf("%lf", &a)) 
    {
        scanf("%lf", &b);
        scanf("%d", &c);

        if (!a && !b && !c) break;
        if (kase++) printf("\n");

        printf("Case %d: %.*f", kase, c, a / b);
    }

}