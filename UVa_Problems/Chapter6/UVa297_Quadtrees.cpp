//
// Created by xinze on 29/06/18.
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

// global
const int len = 32;
int grid[len * len + 5];


void set_grid(int start, int size) {
    FOR(i, start, start + size - 1) grid[i] = 1;
}


int build(const char *s, const int start, const int depth) {
    // sanity check
    assert(strlen(s) >= 4 || strlen(s) == 1);
    auto s_size = (int)pow((32 / pow(2.0, (double) depth)), 2.0);

    if (strlen(s) == 1) {
        if (s[0] == 'f') set_grid(0, len * len);
        return s_size;
    }

    int curr = 0, i = 0;
    while (curr < strlen(s) && i < 4) {
        // curr block is full
        if (s[curr] == 'f') {
            set_grid(start + s_size * i, s_size);
            curr++;
        // curr block contains subtrees
        } else if (s[curr] == 'p') {
            curr++;
            curr += build(s + curr, start + s_size * i, depth + 1);
        // curr block is empty
        } else // s[curr] == 'e'
            curr += 1;
        i++;
    }

    return curr;
}


// count all the pixels
int stats() {
    int pixels = 0;

    F(i, len * len)
        if (grid[i]) pixels++;

    return pixels;
}


// main driver
int main() {
#ifdef LOCAL
    freopen("./UVa297.fin", "r", stdin);
#endif

    int n; s(n);
    W(n) {
        // retrieve the input
        char fi[MAXN], se[MAXN];
        MEM(fi, 0); MEM(se, 0);
        ss(fi); ss(se);

        // initialization...
        MEM(grid, 0);
        build(fi, 0, 0);
        build(se, 0, 0);

        int res = stats();
        printf("There are %d black pixels.\n", res);
    }

    return 0;
}


