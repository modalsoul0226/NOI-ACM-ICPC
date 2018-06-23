//
// Created by xinze on 23/06/18.
//
#include <iostream>
#include <cstdio>

using namespace std;

typedef struct Double_ll {
    int left;
    int right;

    explicit Double_ll(int left=-1, int right=-1): left(left), right(right) {}
} dll;


void init(dll *boxes, const int& n) {
    for (int i = 0; i <= n + 1; i++)
        boxes[i] = dll(i - 1, i + 1);
}

void swap(dll *boxes, const int& x, const int& y, int& start) {
    if (x == start) start = y;
    else if (y == start) start = x;

    int x_left = boxes[x].left, x_right = boxes[x].right;
    int y_left = boxes[y].left, y_right = boxes[y].right;

    if (x_right == y) {
        boxes[x_left].right = y;
        boxes[y_right].left = x;

        boxes[x].left = y;
        boxes[x].right = y_right;

        boxes[y].left = x_left;
        boxes[y].right = x;

        return;
    } else if (x_left == y) {
        boxes[y_left].right = x;
        boxes[x_right].left = y;

        boxes[x].left = y_left;
        boxes[x].right = y;

        boxes[y].left = x;
        boxes[y].right = x_right;

        return;
    }

    boxes[x_left].right = y;
    boxes[x_right].left = y;

    boxes[y_left].right = x;
    boxes[y_right].left = x;

    boxes[x].left = y_left;
    boxes[x].right = y_right;

    boxes[y].left = x_left;
    boxes[y].right = x_right;
}

void add_to_left(dll *boxes, const int& x, const int& y, int& start) {
    if (boxes[x].right == y) return;
    if (x == start) start = boxes[x].right;
    else if (y == start) start = x;

    // Take care of neighbours of x.
    int x_left = boxes[x].left, x_right = boxes[x].right;
    boxes[x_left].right = x_right;
    boxes[x_right].left = x_left;

    // Take care of neighbours of y.
    int y_left = boxes[y].left;
    boxes[y_left].right = x;
    boxes[x].left = y_left;

    boxes[x].right = y;
    boxes[y].left = x;
}

void add_to_right(dll *boxes, const int& x, const int& y, int& start) {
    if (x == start) start = boxes[x].right;

    // Take care of neighbours of x.
    int x_left = boxes[x].left, x_right = boxes[x].right;
    boxes[x_left].right = x_right;
    boxes[x_right].left = x_left;

    // Take care of neighbours of y.
    int y_right = boxes[y].right;
    boxes[y_right].left = x;
    boxes[x].right = y_right;

    boxes[x].left = y;
    boxes[y].right = x;
}

void print_boxes(dll *boxes, const int& start, const int& n) {
    dll curr = boxes[start];

    cout << start << " ";
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++) {
        cout << curr.right << " ";
        curr = boxes[curr.right];
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("./UVa12657.test", "r", stdin);
#endif

//    ios_base::sync_with_stdio(0);
    int n, m; int kase = 1;
    while (scanf("%d%d", &n, &m) == 2) {
//        printf("%d %d\n", n, m);
        dll boxes[n + 2]; init(boxes, n);

        int start = 1, inv = 0;
        while (m--) {
            int op; scanf("%d", &op);
            if (op == 4) { inv = 1 - inv; continue; }

            int X, Y;
            scanf("%d%d", &X, &Y);
//            printf("%d %d %d\n", op, X, Y);
//            cout << op;
//            cout << X << Y;
            if (op == 3) { swap(boxes, X, Y, start); continue; }

            if (inv) op = 3 - op;

            if (op == 1)
                add_to_left(boxes, X, Y, start);
            else
                add_to_right(boxes, X, Y, start);
//            print_boxes(boxes, start, n);
        }

//        printf("start: %d\n", start);

        long long sum = start; dll curr = boxes[start];
        for (int i = 0; i + 2 < n; i += 2) {
            int tmp = boxes[curr.right].right;
            sum += tmp;
            curr = boxes[tmp];
        }
//        printf("22222222222\n");

//        cout << inv << " " << n << endl;
        if (inv && n % 2 == 0) sum = (long long)(1 + n) * n / 2 - sum;
        cout << "Case " << kase++ << ": " << sum << endl;
    }

    return 0;
}

