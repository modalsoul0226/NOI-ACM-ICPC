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
int n; // the size of the prime ring
int vis[16], is_p[32]; // check whether a given number is used before or not

// check whether a number is prime or not
int is_prime(int num) {
    FOR(i, 2, sqrt(num))
        if (!(num % i))
            return 0;
    
    return 1;
}

// the routine for building the prime ring
void build(int *A, int cur) {
    if (cur == n && is_p[A[0] + A[n - 1]]) {
        F(i, n) {
            if (i) printf(" %d", A[i]);
            else printf("%d", A[i]);
        }
        printf("\n");
        return;
    }

    // try to fill in A[cur] with different nums
    FOR(i, 1, n - 1) {
        int num = i + 1;
        if (vis[i]) continue; // continue if we have already used this num
        if (!is_p[A[cur - 1] + num]) // give up if the adjacent sum is not prime
            continue;
        
        vis[i] = 1;
        A[cur] = num;
        // debug
        // FOR(i, 0, cur) printf("%d ", A[i]); printf("\n");
        build(A, cur + 1);
        vis[i] = 0;
    }
}

// main driver
int main() {
#ifdef LOCAL
    freopen("fin/UVa524", "r", stdin);
#endif
    
    int A[16], kase = 0; 
    
    // initialize the lookup table
    MEM(is_p, 0); 
    F(i, 32) if (i >= 2) is_p[i] = is_prime(i);

    while (s(n) != EOF) {
        MEM(A, 0); A[0] = 1;

        if (kase++) printf("\n");
        printf("Case %d:\n", kase);
        build(A, 1);
    }

    return 0;
}
