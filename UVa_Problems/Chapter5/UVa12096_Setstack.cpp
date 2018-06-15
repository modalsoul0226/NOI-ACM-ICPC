#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;

typedef set<int> Set;
map<Set, int> IDCache;
vector<Set> SetCache;

/**
 * Get ID of the given set.
 * If the set doesn't exist,
 * add a new one.
 */
int ID(Set s) {
    if (IDCache.count(s)) return IDCache[s];
    
    SetCache.push_back(s);
    return IDCache[s] = SetCache.size() - 1;
}

int main() {
#ifdef LOCAL
    freopen("./UVa12096.fin", "r", stdin);
#endif

    int num; cin >> num;
    while (num--) {
        stack<int> s;
        int n; cin >> n;
        while (n--) {
            string op; cin >> op;
            if (op[0] == 'P') s.push(ID(Set()));
            else if (op[0] == 'D') s.push(s.top());
            else {
                Set s1 = SetCache[s.top()]; s.pop();
                Set s2 = SetCache[s.top()]; s.pop();
                Set x;

                if (op[0] == 'U') set_union(ALL(s1), ALL(s2), INS(x));
                else if (op[0] == 'I') set_intersection(ALL(s1), ALL(s2), INS(x));
                else { x = s2; x.insert(IDCache[s1]); }
                s.push(ID(x));
            }
            cout << SetCache[s.top()].size() << endl;
        }
        cout << "***\n";
    }

    return 0;
}