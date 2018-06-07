#include <stdio.h>
#include <string.h>
#define ALPHA_SIZE 26
#define MAX_N 1010

int main() {
#ifdef LOCAL
    freopen("./UVa489.fin", "r", stdin);
#endif

    int kase = 0;
    while (scanf("%d", &kase) && kase != -1) {
        printf("Round %d\n", kase);

        // Initialize vars.
        int table[ALPHA_SIZE]; memset(table, 0, sizeof(table));
        char input[MAX_N]; memset(input, 0, sizeof(input));
        char guess[MAX_N]; memset(guess, 0, sizeof(guess));
        scanf("%s", input); scanf("%s", guess);

        // Initialize continued...
        int chance = 6, left = 0;
        for (int i = 0; i < strlen(input); i++) {
            int idx = input[i] - 'a';
            if (!table[idx]) left++;
            table[idx] = 1;
        }

        // Guessing...
        for (int i = 0; i < strlen(guess); i++) {
            int guess_idx = guess[i] - 'a';

            if (table[guess_idx] == 1) {
                left--;
                if (!left) { printf("You win.\n"); break; }
            } else {
                chance--;
                if (chance < 0) { printf("You lose.\n"); break; }
            }
            table[guess_idx]--;
        }
        
        if (chance >= 0 && left > 0)
            printf("You chickened out.\n");
    }
}