#include <stdio.h>
#include <string.h>

int main() {
#ifdef LOCAL
    freopen("./UVa133.fin", "r", stdin);
#endif

    int n = 0, step_a = 0, step_b = 0;

    while (scanf("%d%d%d", &n, &step_a, &step_b) == 3 && n) {
        // Initialization.
        int group[n]; for (int i = 0; i < n; i++) group[i] = 1;
        int left = n, idx_a = 0, idx_b = n - 1, comp_b = 0;
        
        while (left) {
            // Proceed to the next available person.
            while (!group[idx_a]) idx_a = (idx_a + 1) % n;
            while (!group[idx_b])
                { comp_b = (comp_b + 1) % n; idx_b = n - 1 - comp_b; }
            if (left < n) printf(",");
            // printf("comp_b: %d idx_b:%d idx_a:%d\n", comp_b, idx_b, idx_a);
            
            // A selects the next person.
            for (int i = 0; i < step_a - 1; i++) {
                do {
                    idx_a = (idx_a + 1) % n;
                } while (!group[idx_a]);
            }

            // B selects the next person.
            for (int i = 0; i < step_b - 1; i++) {
                do {
                    comp_b = (comp_b + 1) % n;
                    idx_b = n - 1 - comp_b;
                } while (!group[idx_b]);
            }
            // printf("idx_a:%d idx_b:%d\n", idx_a, idx_b);

            // Hand out the dole.
            if (idx_a == idx_b)
                { left--; group[idx_a] = 0; printf("%3d", idx_a + 1); }
            else {
                left -= 2;
                group[idx_a] = 0; group[idx_b] = 0;
                printf("%3d", idx_a + 1); printf("%3d", idx_b + 1);
            }
        }
        printf("\n");
    }

    return 0;
}