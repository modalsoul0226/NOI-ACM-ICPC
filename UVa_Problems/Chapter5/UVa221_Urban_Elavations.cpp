#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 105

struct Building {
    int id;
    double x, y, width, depth, height;

    bool operator < (const Building& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
} b[MAXN]; // an array of buildings


int n;           // number of buildings
int x[MAXN * 2]; // an array of intervals

// Check wether a specified point is covered by building i.
bool cover(int i, double mx) {
    return b[i].x <= mx && mx <= b[i].x + b[i].width;
}

// Check whether a building i is visible at a specified point.
bool visible(int i, double mx) {
    if (!cover(i, mx)) return false;
    for (int j = 0; j < n; j++) 
        if (cover(j, mx) && b[j].y < b[i].y && b[j].height >= b[i].height)
            return false;
    
    return true;
}

int main() {
#ifdef LOCAL
    freopen("./UVa221.fin", "r", stdin);
#endif

    int kase = 1;
    while (cin >> n && n) {
        if (kase > 1) cout << endl;
        cout << "For map #" << kase++ << ", the visible buildings are numbered as follows:\n";

        for (int i = 0; i < n; i++) {
            cin >> b[i].x >> b[i].y >> b[i].width >> b[i].depth >> b[i].height;
            x[i * 2] = b[i].x; x[i * 2 + 1] = b[i].x + b[i].width;
            b[i].id = i + 1;
        }

        sort(b, b + n);
        sort(x, x + 2 * n); int m = unique(x, x+2*n) - x;

        cout << b[0].id;
        for (int i = 1; i < n; i++) {
            bool vis = false;
            for (int j = 0; j < m - 1; j++)
                if (visible(i, (x[j + 1] + x[j]) / 2))
                    { vis = true; break; }
            
            if (vis) cout << " " << b[i].id;
        }
        cout << endl;
    }

    return 0;
}


// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// #define MAXN 105

// struct Building {
//     int id;
//     double x, y, width, depth, height;

//     bool operator < (const Building& other) const {
//         return x < other.x || (x == other.x && y < other.y);
//     }
// } b[MAXN]; // an array of buildings


// int n;           // number of buildings
// int x[MAXN * 2]; // an array of intervals

// // Check wether a specified point is covered by building i.
// bool cover(int i, double mx) {
//     return b[i].x <= mx && mx <= b[i].x + b[i].width;
// }

// // Check whether a building i is visible at a specified point.
// bool visible(int i, double mx) {
//     if (!cover(i, mx)) return false;
//     for (int j = 0; j < n; j++) 
//         if (cover(j, mx) && b[j].y < b[i].y && b[j].height >= b[i].height)
//             return false;
    
//     return true;
// }

// int main() {
// #ifdef LOCAL
//     freopen("./UVa221.fin", "r", stdin);
// #endif

//     int kase = 1;
//     while (scanf("%d", &n) == 1 && n) {
//         if (kase > 1) printf("\n");
//         cout << "For map #" << kase++ << ", the visible buildings are numbered as follows:\n";

//         for (int i = 0; i < n; i++) {
//             scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].width, &b[i].depth, &b[i].height);
//             x[i * 2] = b[i].x; x[i * 2 + 1] = b[i].x + b[i].width;
//             b[i].id = i + 1;
//         }

//         sort(b, b + n);
//         sort(x, x + 2 * n); int m = unique(x, x+2*n) - x;

//         cout << b[0].id;
//         for (int i = 1; i < n; i++) {
//             bool vis = false;
//             for (int j = 0; j < m - 1; j++)
//                 if (visible(i, (x[j + 1] + x[j]) / 2))
//                     { vis = true; break; }
            
//             if (vis) cout << " " << b[i].id;
//         }
//         cout << endl;
//     }

//     return 0;
// }