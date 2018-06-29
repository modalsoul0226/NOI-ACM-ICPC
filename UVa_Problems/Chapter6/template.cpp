//
//           __
//    ____  / /_     ____ ___  __  __
//   / __ \/ __ \   / __ `__ \/ / / /
//  / /_/ / / / /  / / / / / / /_/ /
//  \____/_/ /_/  /_/ /_/ /_/\__, /
//                          /____/
//
// Macros collected and summarized from online src
// e.g. github, Quora...
//
// Collected mainly from:
// https://github.com/chenbowen/Competitive-Programming
// CR: Bowen Chen
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_LINE = 256;
const int MAXN = (int)1e5 + 5;
const double PI = acos(-1.0);

typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;

#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define W(n)                        while((n)--)
#define F(i,n)                      for(int (i)=0;(i)<(n);++(i))
#define EN_F(i,n)                   for(auto (i):(n))
#define FD(i,n)                     for(int (i)=((n)-1);(i)>=0;--(i))
#define FOR(i,s,e)                  for(int (i)=(s);(i)<=(e);(i)++)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define op(a)                       cout<<(a)<<endl
#define debug                       printf("here!!!\n")
#define fi                          first
#define se                          second
#define pb                          push_back
#define all(a)                      (a).begin(), (a).end()
#define in(a,b)                     ((b).find(a) != (b).end())
#define sz(a)                       ((int)((a).size()))
#define s(n)                        scanf("%d",&(n))
#define s2(n,m)                     scanf("%d%d",&(n),&(m))
#define sc(n)                       scanf("%c",&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

// main driver
int main() {
#ifdef LOCAL
    freopen("./sample_file", "r", stdin);
#endif

    int n = 10; auto list = VI();
    W(n) list.pb(n);
    sort(all(list));

    EN_F(i,list) cout << i; cout << endl;

    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    return 0;
}
