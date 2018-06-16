#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define LEN 60

void print_name(const string& name, const int& len) {
    cout << name;
    for (int i = 0; i < len - name.length(); i++) cout << " ";
}

int main() {
#ifdef LOCAL
    freopen("./UVa400.fin", "r", stdin);
#endif

    int n; 
    while (cin >> n && n != EOF) {
        for (int i = 0; i < 60; i++) cout << "-"; cout << endl;
        vector<string> files(n);
        
        string s; int max_len = 0;
        for (int i = 0; i < n; i++) {
            cin >> s; files[i] = s; 
            max_len = max_len > s.length() ? max_len : s.length();
        }
        sort(files.begin(), files.end());
        int c = (LEN - max_len) / (max_len + 2) + 1;
        int r = (n % c) ? (n / c) + 1 : (n / c);

        for (int i = 0; i < r; i++) {
            int j;
            for (j = 0; j < c - 1; j++)
                if (r * j + i < n) print_name(files[r * j + i], max_len + 2);
            if (r * (c - 1) + i < n) print_name(files[r * (c - 1) + i], max_len);
            cout << endl;
        }

    }

    return 0;
}