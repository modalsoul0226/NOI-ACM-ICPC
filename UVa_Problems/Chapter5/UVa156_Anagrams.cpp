#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string,int> dict;
vector<string> words;
vector<string> ans;

string unify(const string& s) {
    string ans = s;
    
    for (int i = 0; i < s.length(); i++)
        ans[i] = tolower(s[i]);
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("./UVa156.fin", "r", stdin);
#endif

    string s;
    while (cin >> s && s[0] != '#') {
        words.push_back(s);

        string tmp = unify(s);
        if (!dict.count(tmp)) dict[tmp] = 1;
        else dict[tmp]++;
    }

    for (int i = 0; i < words.size(); i++)
        if (dict[unify(words[i])] == 1) ans.push_back(words[i]);
    
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

    return 0;
}