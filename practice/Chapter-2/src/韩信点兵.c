#include <stdio.h>
#define SIZE 3

int main()
{

#ifdef LOCAL
    freopen("../data_in/2_2_data.in", "r", stdin);
    freopen("../data_out/2_2_data.out", "w", stdout);
#endif
    
    int remainder_list[3];
    int kase = 0, found = 0;

    while (scanf("%d", remainder_list) == 1) {
        scanf("%d", remainder_list + 1);
        scanf("%d", remainder_list + 2);

        if (kase) printf("\n");

        for (int i = 10; i <= 100; i++) {
            if (i % 3 == remainder_list[0] && 
                i % 5 == remainder_list[1] && 
                i % 7 == remainder_list[2]) {
                    found = 1;
                    printf("Case %d: %d", ++kase, i);
                }
        }

        if (!found) printf("Case %d: No answer", ++kase);
        found = 0;
    }

    return 0;
}
