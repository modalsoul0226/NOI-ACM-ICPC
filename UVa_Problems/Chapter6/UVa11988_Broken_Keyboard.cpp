#include <cstdio>
#include <cstring>
#include <list>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;
int last, curr, next[maxn];
char s[maxn];

int main() {
#ifdef LOCAL
    freopen("./UVa11988.fin", "r", stdin);
#endif

    string s;
    while (getline(cin, s)) {
        list<char> chars;
        auto curr = chars.begin();

        for (char i: s) {
            if (i == '[') curr = chars.begin();
            else if (i == ']') curr = chars.end();
            else chars.insert(curr, i);
        }

        for (auto c: chars)
            cout << c;
        cout << endl;
    }

//    while (scanf("%s", s + 1) == 1) {
//        auto n = (int)strlen(s + 1);
//        last = curr = 0;
//        next[0] = 0;
//
//        for (int i = 1; i <= n ; i++) {
//            char ch = s[i];
//            if (ch == '[') curr = 0;
//            else if (ch == ']') curr = last;
//            else {
//                next[i] = next[curr];
//                next[curr] = i;
//                if (curr == last) last = i;
//                curr = i;
//            }
//        }
//
//        for (int i = next[0]; i != 0; i = next[i])
//            printf("%c", s[i]);
//        printf("\n");
//    }

    return 0;
}