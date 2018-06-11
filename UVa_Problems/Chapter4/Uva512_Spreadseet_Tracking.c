#include <stdio.h>
#include <string.h>

struct Command {
    char name[10];
    int r1, c1, r2, c2;
    int a, x[20];
} cmd[10000];

/**
 * Save n commands. 
 */
void save_cmd(int n) {
    memset(cmd, 0, sizeof(cmd));
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd[i].name);
        
        if (cmd[i].name[0] == 'E') {
            scanf("%d%d", &cmd[i].r1, &cmd[i].c1);
            scanf("%d%d", &cmd[i].r2, &cmd[i].c2);
        
        } else {
            scanf("%d", &cmd[i].a);
            for (int j = 0; j < cmd[i].a; j++){
                scanf("%d", cmd[i].x + j);
            }
        }
    }
}

void print_cmd(int n) {
    for (int i = 0; i < n; i++) {
        if (cmd[i].name[0] == 'E') {
            printf("r1: %d c1: %d ", cmd[i].r1, cmd[i].c1);
            printf("r2: %d c2: %d\n", cmd[i].r2, cmd[i].c2);
        
        } else {
            printf("A: %d", cmd[i].a);
            for (int j = 0; j < cmd[i].a; j++){
                printf(" %d", *(cmd[i].x + j));
            }
            printf("\n");
        }
    }
}
/**
 * Replay the saved command.
 */
int replay(int *r, int *c, int n) {

    for (int i = 0; i < n; i++) {
        if (cmd[i].name[0] == 'E') {
            if (cmd[i].r1 == *r && cmd[i].c1 == *c) 
                { *r = cmd[i].r2; *c = cmd[i].c2; }
            else if (cmd[i].r2 == *r && cmd[i].c2 == *c)
                { *r = cmd[i].r1; *c = cmd[i].c1; }
        
        } else if (cmd[i].name[0] == 'I') {
            int dr = 0, dc = 0;
            if (cmd[i].name[1] == 'R') {
                for (int j = 0; j < cmd[i].a; j++) {
                    if (cmd[i].x[j] <= *r) dr++;
                }
            } else {
                for (int j = 0; j < cmd[i].a; j++) {
                    if (cmd[i].x[j] <= *c) dc++;
                }
            }
            *r += dr; *c += dc;

        } else {
            int dr = 0, dc = 0;
            if (cmd[i].name[1] == 'R') {
                for (int j = 0; j < cmd[i].a; j++) {
                    if (cmd[i].x[j] == *r) return 1;
                    else if (cmd[i].x[j] < *r) dr--;
                }
            } else {
                for (int j = 0; j < cmd[i].a; j++) {
                    if (cmd[i].x[j] == *c) return 1;
                    else if (cmd[i].x[j] < *c) dc--;
                }
            }
            *r += dr; *c += dc;
        }
    }

    return 0;
}

int main() {
#ifdef LOCAL
    freopen("./UVa512.fin", "r", stdin);
#endif

    int r = 0, c = 0, n = 0, kase = 1;
    while (scanf("%d%d%d", &r, &c, &n) == 3 && r) {
        save_cmd(n);

    #ifdef DEBUG
        print_cmd(n);
    #endif
        if (kase > 1) printf("\n");
        printf("Spreadsheet #%d\n", kase++);
        int num = 0; scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            int r0 = 0, c0 = 0; scanf("%d%d", &r0, &c0);

            printf("Cell data in (%d,%d) ", r0, c0);
            if (replay(&r0, &c0, n)) printf("GONE\n");
            else printf("moved to (%d,%d)\n", r0, c0);
        } 
    }

    return 0;
}