//
// Created by xinze on 26/06/18.
//
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = (int)1e5;
const int MAXINT = 0x7fffffff;

// cin acc
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// definition of a tree node
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int val=0): val(val), left(nullptr), right(nullptr) {}
} t_node;


/**
 * FOR DEBUG PURPOSE
 */
void print_list(const int *list, const int& size) {
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
}

/**
 * FOR DEBUG PURPOSE
 * (IN-ORDER TRAVERSAL)
 */
void print_tree(const t_node *root) {
    if (!root) return;

    print_tree(root->left);
    printf("%d ", root->val);
    print_tree(root->right);
}


/**
 * Allocate a new node.
 */
t_node *new_node(int val=0) { return new t_node(val); }


/**
 * Build a tree from in order sequence and
 * post order sequence.
 */
t_node *build_tree(const int *in, const int *post, const int& size) {
    int root_val = post[size - 1];
    auto root = new_node(root_val);

    if (size == 1) return root;

    int i;
    for (i = 0; i < size; i++)
        if (in[i] == root_val) break;

    // build the left subtree
    if (i > 0) {
        int left_size = i;
        root->left = build_tree(in, post, left_size);
    }
    // build the right subtree
    if (i < size - 1) {
        int right_size = size - 1 - i;
        root->right = build_tree(in + i + 1, post + i, right_size);
    }

    return root;
}

vector<int> dfs_min(const t_node *root) {
    if (!root) return {0, 0}; // since val can only be positive int
    else if (!root->left && !root->right) {
        return {root->val, root->val}; // here, root is the leaf

    } else {
        vector<int> left = {MAXINT, MAXINT}; vector<int> right = {MAXINT, MAXINT};
        if (root->left) left = dfs_min(root->left);
        if (root->right) right = dfs_min(root->right);

        auto res = vector<int>();
        if (left[0] < right[0] || (left[0] == right[0] && left[1] < right[1])) {
            res.push_back(left[0] + root->val);
            res.push_back(left[1]);
        } else {
            res.push_back(right[0] + root->val);
            res.push_back(right[1]);
        }

        return res;
    }
}


int main() {
#ifdef LOCAL
    freopen("./UVa548.fin", "r", stdin);
#endif

    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        int in_order[MAXN]; memset(in_order, 0, sizeof(in_order));
        int post_order[MAXN]; memset(post_order, 0, sizeof(post_order));

        int size = 0;
        while (ss >> in_order[size++]); size--;
//        print_list(in_order, size);
        for (int i = 0; i < size; i++) cin >> post_order[i];
//        print_list(post_order, size);
        getline(cin, line); // skip the new line char

        t_node *root = build_tree(in_order, post_order, size);
//        print_tree(root); printf("\n");
        auto res = dfs_min(root);
        printf("%d\n", res[1]);
    }

    return 0;
}