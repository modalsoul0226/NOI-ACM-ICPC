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
int k, n;
int A[80];

bool has_dup(int *A, int size) {
    FOR(s_len, 1, size / 2) {
        int i = size - 2 * s_len, j = size - s_len;
        int ok = 0;

        F(k, s_len) 
            if (A[i + k] != A[j + k])
                { ok = 1; break; }

        if (!ok)
            return true;
    }

    return false;
}

int build(int *A, int cur) {
    if (!(k--)) {
        F(i, cur)
            printf("%c", 'A' + A[i]);
        printf("\n");

        return 1;
    }

    F(i, n) {
        A[cur] = i;
        if (has_dup(A, cur + 1)) 
            continue;

        // debug
        // FOR(j, 0, cur) printf("%d ", A[j]); printf("\n");

        if (build(A, cur + 1)) 
            return 1;
    }

    return 0;
}

// main driver
int main() {
#ifdef LOCAL
    freopen("./fin/UVa129", "r", stdin);
#endif

    while (s2(k, n) != EOF) {
        MEM(A, 0);
        build(A, 0);
    }

    return 0;
}
