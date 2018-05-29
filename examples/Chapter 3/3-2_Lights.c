#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int k = 0, n = 0;
    scanf("%d %d", &n, &k);
    if (k > n) 
    {
        fprintf(stderr, "Invalid input.\n");
        exit(1);
    }

    int lights[n + 1];
    memset(lights, 0, sizeof(int) * (n + 1));

    for (int i = 1; i <= k; i++) 
    {
        for (int j = 1; j <= n / i; j++)
        {
            lights[j * i] = 1 - lights[j * i];
        }
    }

    int kase = 0;
    for (int i = 1; i <= n; i++)
    {
        if (lights[i])
        {
            if (kase++) printf(" ");
            printf("%d", i);
        }
    }
    printf("\n");
}