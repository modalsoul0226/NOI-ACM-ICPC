#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
#ifdef LOCAL
    freopen("UVa10474.fin", "r", stdin);
#endif
    
    int n, p, kase = 1;
    while (scanf("%d%d", &n, &p) == 2 && n){
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", arr + i);
        sort(arr, arr + n);

        cout << "CASE# " << kase++ << ":\n";
        
        // for (int j = 0; j < n; j++) printf("%d", arr[j]); printf("\n");
        
        int target;
        for (int i = 0; i < p; i++) {
            scanf("%d", &target);
            int offset = lower_bound(arr, arr + n, target) - arr;

            if (arr[offset] == target) cout << target << " found at " << offset + 1 << "\n";
            else cout << target << " not found\n";
        }
    }

    return 0;
}
