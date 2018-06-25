//
// Created by xinze on 25/06/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 256;
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    explicit TreeNode(): val(0), left(nullptr), right(nullptr) {}
} t_node;


// Allocate a new node with dynamic memory.
t_node *new_node () { return new t_node(); }

/**
 * Add a new node with specified val and location.
 * if
 */
int add_new_node(t_node *root, const int& val, const char *location) {
    t_node *curr = root;

    for (int i = 0; ; i++) {
        if (location[i] == ')') break;
        else if (location[i] == 'L') {
            if (!curr->left)
                curr->left = new_node();
            curr = curr->left;

        } else {
            if (!curr->right)
                curr->right = new_node();
            curr = curr->right;
        }
    }

    // The node has already been assigned a value.
    if (curr->val) return -1;
    curr->val = val;

    return 0;
}

/**
 * Return a vector of node numbers.
 */
int bfs(t_node *root, vector<int>& res) {
    auto q = queue<t_node *>();
    q.push(root);

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        if (!node->val) return -1;
        res.push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return 0;
}


int main() {
#ifdef LOCAL
    freopen("./UVa122.fin", "r", stdin);
#endif

    char s[maxn];
    while (scanf("%s", s) == 1) {
        t_node *root = new_node();

        int status = 0;
        while (strcmp(s, "()") != 0) {
            int val; sscanf(s + 1, "%d", &val);
            char *loc = strchr(s, ',') + 1;
            status += add_new_node(root, val, loc);

            scanf("%s", s);
        }

        if (status) {
            cout << "not complete\n";
            continue;
        }

        auto res = vector<int>();
        status = bfs(root, res);
        if (status) cout << "not complete\n";
        else {
            for (int i = 0; i < res.size(); i++) {
                if (i) cout << " ";
                cout << res[i];
            }
            cout << endl;
        }
    }

    return 0;
}