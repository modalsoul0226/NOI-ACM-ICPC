//
// Created by xinze on 25/06/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

// TLE solution
int traverse(int *tree, const int& size) {
    int curr = 1;
    for (;;) {
        int tmp;
        if (!tree[curr]) tmp = curr * 2;
        else tmp = curr * 2 + 1;

        if (tmp > size) return curr;
        else { tree[curr] = 1 - tree[curr]; curr = tmp; }
    }
}

int main() {
#ifdef LOCAL
    freopen("./UVa679.fin", "r", stdin);
#endif

    int n; cin >> n;
    while (n--) {
        int D, I;
        scanf("%d%d", &D, &I);

        int res = 1;
        for (int i = 1; i < D; i++) {
            if (I % 2) { res = res * 2; I = (I + 1) / 2; }
            else { res = res * 2 + 1; I = I / 2; }
        }

        assert(res != 1);
        cout << res << endl;
//        int size = (1 << D) - 1;
//        int tree[size + 1]; memset(tree, 0, sizeof(tree));
//
//        int status = -1;
//        while (I--)
//            status = traverse(tree, size);
//
//        assert(status != -1);
//        cout << status << endl;
    }

    return 0;
}