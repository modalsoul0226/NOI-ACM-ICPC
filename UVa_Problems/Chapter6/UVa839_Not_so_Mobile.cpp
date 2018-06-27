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

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

// definition of a tree node
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int val=0, int weight=0): val(val), left(nullptr), right(nullptr) {}
} t_node;


t_node *new_node() { return new t_node(); }

/**
 * Build the mobile from stdin.
 */
bool build_tree(t_node *root) {
    bool ok = true;
    assert(root->val == 0);

    t_node *left = (root->left = new_node());
    t_node *right = (root->right = new_node());
    // get weights and distance from stdin
    int w1, d1, w2, d2;
    s2(w1, d1); s2(w2, d2);

#ifdef DEBUG
    printf("%d %d %d %d\n", w1, d1, w2, d2);
#endif

    if (w1)
        left->val = w1;
    else if (!build_tree(left))
        ok = false;

    if (w2)
        right->val = w2;
    else if (!build_tree(right))
        ok = false;

    root->val = left->val + right->val;
    return ok && left->val * d1 == right->val * d2;
}


// main driver
int main() {
#ifdef LOCAL
    freopen("./UVa839.fin", "r", stdin);
#endif

    int n, kase = 0; s(n);
    W(n) {
        string line; getline(cin, line); // skip the new line char
        if (kase++) printf("\n");

        t_node *root = new_node();
        if (build_tree(root))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
