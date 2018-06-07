#include <stdio.h>
#include <string.h>

int main() {
#ifdef LOCAL
    freopen("./UVa133.fin", "r", stdin);
#endif

    int n = 0, step_a = 0, step_b = 0;

    while (scanf("%d%d%d", &n, &step_a, &step_b) == 3 && n) {
        // Initialization.
        int group[n + 1]; for (int i = 0; i <= n; i++) group[i] = 1;
        int left = n, idx_a = 1, idx_b = n, comp_b = 1;
        
        while (left) {
            if (left < n) printf(",");
            printf("comp_b: %d idx_b:%d\n idx_a:%d", comp_b, idx_b, idx_a);
            idx_a = (idx_a + step_a - 1) % n;
            comp_b = (comp_b + step_b - 1) % n;
            idx_b = n - comp_b + 1;

            while (!group[idx_a]) idx_a = (idx_a + 1) % n;
            while (!group[idx_b])
                { comp_b = (comp_b + 1) % n; idx_b = n - comp_b + 1; }
            
            if (idx_a == idx_b)
                { left--; group[idx_a] = 0; printf("%3d", idx_a); }
            else {
                left -= 2;
                group[idx_a] = 0; group[idx_b] = 0;
                printf("%3d", idx_a); printf("%3d", idx_b);
            }

            while (!group[idx_a]) idx_a = (idx_a + 1) % n;
            while (!group[idx_b])
                { comp_b = (comp_b + 1) % n; idx_b = n - comp_b + 1; }
        }
        printf("\n");
    }

    return 0;
}