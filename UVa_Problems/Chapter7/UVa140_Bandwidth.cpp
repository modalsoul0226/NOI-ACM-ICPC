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
const long double PI = acos(-1.0L);

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

// global variables (if any)
int n;
char s[1001];
int id[256], ch[8], pos[8];
int vis[8], A[8], sol[8];
int min_width;
vector<set<int> > G;


void dfs(int *A, int cur, int local_max) {
    if (cur == n) {
        if (local_max < min_width) {
            min_width = local_max;
            memcpy(sol, A, sizeof(int) * n);
        }
    }

    F(u, n) {
        if (vis[u]) continue;
        A[cur] = u; vis[u] = 1;

        int acc = 0, ok = 1;
        EN_F(v, G[u]) {
            if (!vis[v]) acc++;
            else {
                auto ptr = find(A, A + cur, v);
                int dis = (A + cur) - ptr;

                local_max = max(local_max, dis);
                if (dis >= min_width) { ok = 0; break; }
            }
        }

        // prune
        if (acc >= min_width || !ok) { vis[u] = 0; continue; }
        dfs(A, cur + 1, local_max);
        vis[u] = 0;
    }
}

// main driver
int main() {
#ifdef LOCAL
    freopen("./fin/UVa140", "r", stdin);
#endif

    while (ss(s) && s[0] != '#') {
        MEM(id, 0); MEM(ch, 0); 
        MEM(vis, 0); MEM(pos, 0);
        MEM(A, 0); MEM(sol, 0);
        min_width = 0x7fffffff;

        n = 0; int len = strlen(s);

        FOR(c, 'A', 'Z')
            if (strchr(s, c)) {
                id[c] = n;
                ch[n++] = c;
            }
        
        G = vector<set<int> >();
        F(i, n) G.push_back(set<int>());

        int i = 0, j = 0;
        while (j < len) {
            while (i < len && s[i] != ':') i++;
            while (j < len && s[j] != ';') j++;
           
            for (int k = i + 1; k < j; k++) {
                int uid = id[s[i - 1]];
                int vid = id[s[k]];

                G[uid].insert(vid);
                G[vid].insert(uid);
            }
            i++, j++;
        }

        // debug
        // F(u, n) {
        //     if (G[u].empty()) continue;

        //     printf("%c: ", ch[u]);
        //     EN_F(v, G[u]) printf("%c ", ch[v]);
        //     printf("\n");
        // }
        // printf("---------------\n");
        
        dfs(A, 0, 0);
        F(i, n) printf("%c ", ch[sol[i]]);
        printf("-> "); printf("%d\n", min_width);

        MEM(s, 0);
    }

    return 0;
}
