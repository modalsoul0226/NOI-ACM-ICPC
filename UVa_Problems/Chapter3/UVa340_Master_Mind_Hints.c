#include <stdio.h>
#include <string.h>

#define MAX_N 10
#define MIN(x, y) x < y ? x : y

// /* Hash by chaining */
// /**
//  * Node of a singly linked list.
//  */
// typedef struct node {
//     int val;            // value of the node
//     int freq;           // the frequency counter
//     struct node *next;  // pointer to the next node
// } Node;


// /**
//  * Create a new node.
//  */
// Node *init_node(int val) {
//     Node *node = (Node *)malloc(sizeof(Node));
//     node -> val = val; node->freq = 1; node->next = NULL;

//     return node;
// }

// /**
//  * Add a node with val to the table.
//  * If there exists a node in the table
//  * with the specified value, increment the
//  * frequency counter.
//  */ 
// void add_to_tab(Node **table, int val) {
//     Node *curr = table[val % MAX_N];
    
//     if (!curr) {
//         table[val % MAX_N] = init_node(val);
//     } else {
//         while (curr->next && curr->next->val != val) curr = curr->next;
//         if (!curr->next) curr->next = init_node(val);
//         else curr->next->freq += 1;
//     }
// }

// /**
//  * Check whether there is a node with the specified
//  * value. If there is one, decrement the frequency counter
//  * and return 1. Otherwise, return 0.
//  */
// int check_tab(Node **table, int val) {
//     Node *curr = table[val % MAX_N];

//     while (curr && curr->val != val) curr = curr->next;
//     if (!curr || !(curr->freq)) return 0;
//     else { curr->freq -= 1; return 1; }
// }

// /**
//  * Clean up the table.
//  */
// void free_tab(Node **table) {
//     for (int i = 0; i < MAX_N; i++) {
//         if (!table[i]) continue;

//         Node *curr = table[i];
//         while (curr) {
//             Node *temp = curr->next;
//             free(curr);
//             curr = temp;
//         }
//     }
// }


int main() {

#ifdef LOCAL
    freopen("./UVa340_fin", "r", stdin);
#endif

    int kase = 0, n = 0;
    while (scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", ++kase);
        
        // Build the answer and table.
        int ans[n]; memset(ans, 0, sizeof(ans));
        int ans_tab[MAX_N]; memset(ans_tab, 0, sizeof(ans_tab));
        for (int i = 0; i < n; i++) {
            scanf("%d", ans + i);
            ans_tab[ans[i]]++;
        }

        int res[n]; memset(res, 0, sizeof(res));
        for (;;) {
            // Build and check each of the guess.
            int x = 0, y = 0;
            int res_tab[MAX_N]; memset(res_tab, 0, sizeof(res_tab));
            int temp_tab[MAX_N]; memcpy(temp_tab, ans_tab, sizeof(temp_tab));
            // Get the value for x.
            for (int i = 0; i < n; i++) {
                scanf("%d", res + i);
                if (res[i] == ans[i]) { x++; temp_tab[ans[i]]--; }
                else res_tab[res[i]]++;
            }

            if (!res[0]) break;
            // Get the value for y.
            for (int i = 0; i < MAX_N; i++) {
                y += MIN(temp_tab[i], res_tab[i]);
            }

            printf("    (%d,%d)\n", x, y);
        }
    }
}