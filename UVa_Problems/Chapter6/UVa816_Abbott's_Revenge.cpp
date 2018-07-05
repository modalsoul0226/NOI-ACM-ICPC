//
// Created by xinze on 02/07/18.
//
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


typedef struct Node {
    int r, c;
    Node *parent;
    char turns[4];

    Node(int r, int c): r(r), c(c), parent(nullptr) { MEM(turns, 0); }
} node_t;

// global variables (if any)
const int maxr = 10;
const int maxc = 10;
node_t *maze[maxr][maxc][4];

queue<node_t *> node_q;
queue<int> dir_q;

enum direction { N, E, S, W };
map<char,int> dir;

int init_dir() {
    dir['N'] = N; dir['E'] = E; dir['S'] = S; dir['W'] = W;
}

// compute the next position according
// to current position and direction
void next_pos(int& x, int& y, int d) {
    int dx = 0, dy = 0;

    switch (d) {
        case N:
            dx = -1;
            break;
        case S:
            dx = 1;
            break;
        case E:
            dy = 1;
            break;
        default: // case W
            dy = -1;
            break;
    }

    x += dx; y += dy;
}

// compute the next direction
int next_d(const int& from_d, char turn) {
    // turn left
    if (turn == 'L')
        return (from_d + 1) % 4;
    // turn right
    if (turn == 'R')
        return (from_d - 1) < 0 ? 3 : from_d - 1;
    // forward
    if (turn == 'F')
        return (from_d + 2) % 4;
}


node_t *init() {
    MEM(maze, 0);
    // scan the start point
    int r, c; s2(r, c);
    auto src = new Node(r, c);

    // scan the start dir
    char ch[2]; ss(ch); int d = dir[ch[0]];

    // scan the end point
    s2(r, c);
    auto dest = new Node(r, c); F(i, 4) maze[r][c][i] = dest;

    // scan each node in the maze
    while (s(r) == 1 && r) {
        s(c);

        char s[5]; MEM(s, 0);
        while (ss(s) == 1 && s[0] != '*') {
            auto node = new Node(r, c);

            int idx = dir[s[0]];
            maze[r][c][idx] = node;

            memcpy(node->turns, s + 1, strlen(s));
        }
    }

    int next_r = src->r, next_c = src->c; next_pos(next_r, next_c, d);
    node_t *next_node = maze[next_r][next_c][d];
    if (!next_node) return nullptr;

    next_node->parent = src; node_q.push(next_node);
    dir_q.push(d);

    return dest;
}


void print_maze() {
    F(i, maxr)
        F(j, maxc)
            F(d, 4)
                if (maze[i][j][d]) {
                    node_t *node = maze[i][j][d];
                    printf("%d %d %d ", node->r, node->c, d);
                    printf("%s", node->turns);
                    printf("\n");
                }

}

// the bfs routine
node_t *bfs(node_t *dest) {
    while (!node_q.empty()) {
        node_t *node = node_q.front(); node_q.pop();
        int d = dir_q.front(); dir_q.pop();

        if (node->r == dest->r && node->c == dest->c) return node;

        char *turns = node->turns;
        int from_d = (d + 2) % 4;

        F(i, strlen(turns)) {
            int new_d = next_d(from_d, turns[i]);
            int new_r = node->r, new_c = node->c;
            next_pos(new_r, new_c, new_d);

            // out of bound
            if (new_r < 1 || new_r > 9 || new_c < 1 || new_c > 9) continue;

            node_t *next_node = maze[new_r][new_c][new_d];
//            printf("%d %d %d\n", new_r, new_c, new_d);
            if (!next_node) continue;

            if (!next_node->parent)
                next_node->parent = node;
            else
                continue;

//            printf("%d %d\n", next_node->r, next_node->c);
            node_q.push(next_node); dir_q.push(new_d);
        }
    }

    return nullptr;
}

void print_res(node_t *dest) {
    node_t *curr = dest;
    auto res = vector<node_t *>();

    while (curr) {
        res.push_back(curr);
        curr = curr->parent;
    }

    int count = 0;
    FD(i, res.size()) {
        if (count++ % 10 == 0) printf("\n ");
        printf(" (%d,%d)", res[i]->r, res[i]->c);
    }
    printf("\n");
}

// main driver
int main() {
#ifdef LOCAL
    freopen("./UVa816.fin", "r", stdin);
#endif

    init_dir();

    char name[MAX_LINE];
    while (ss(name) == 1 && strncmp(name, "END", 3) != 0) {
        printf("%s", name);

        node_q = queue<node_t *>();
        dir_q = queue<int>();

        auto dest = init();
        if (!dest) {
            printf("\n  No Solution Possible\n");
            continue;
        }

//        print_maze();
        node_t *res;
        if ((res = bfs(dest))) {
            print_res(res);
        } else
            printf("\n  No Solution Possible\n");
    }
}

