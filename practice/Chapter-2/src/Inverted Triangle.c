#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

#ifdef LOCAL
    freopen("../data_in/2_2_data.in", "r", stdin);
    freopen("../data_out/2_2_data.out", "w", stdout);
#endif
    
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <size of the inverted triangle>\n", argv[0]);
        exit(1);
    }
    int size = (int)strtol(argv[1], NULL, 10);
    
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < i; j++) printf(" ");
        for (int j = 0; j < 2 * (size - i) - 1; j++) printf("#");
        printf("\n");
    }

    return 0;
}
