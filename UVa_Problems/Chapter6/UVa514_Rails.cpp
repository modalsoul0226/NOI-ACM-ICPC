#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int test(const int& target, int *A, vector<int>& C, int& start) {
    // cout << "start: " << start << endl;
    // cout << "target: "<< target << endl;


    if (!A[target]) {
        // while (A[start]) start++;

        for (start; start <= target; start++) 
            { C.push_back(start); A[start] = 1; }
        C.pop_back(); 

    } else if (C.back() == target) C.pop_back();
    else return -1;

    return 0;
}

int main() {
#ifdef LOCAL
    freopen("./UVa514.fin", "r", stdin);
#endif

    int n, kase = 0;
    while (cin >> n && n) {
        // if (kase++) cout << endl;

        int tmp;
        while (cin >> tmp && tmp) {
            int A[n + 1]; memset(A, 0, sizeof(A));
            int ans[n]; memset(ans, 0, sizeof(ans)); ans[0] = tmp;
            
            for (int i = 1; i < n; i++) cin >> ans[i];
            // for (int i = 0; i < n; i++) cout << ans[i]; cout << endl;

            vector<int> C = vector<int>();

            int start = 1, ok = 1;
            for (int i = 0; i < n; i++) {
                if (test(ans[i], A, C, start)) { ok = 0; break;}
                // for (int i = 0; i < C.size(); i++) cout << C[i] << " "; cout << endl;
            }
            cout << (ok ? "Yes\n" : "No\n");
        }
        cout << endl;
    }
}