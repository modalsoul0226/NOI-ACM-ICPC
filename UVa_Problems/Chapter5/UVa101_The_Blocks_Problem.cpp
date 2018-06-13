#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> block_world[30];

void init() {
    for (int i = 0; i < n; i++) {
        block_world[i].push_back(i);
    }
}

/**
 * Search for which pile the
 * target is in.
 */
int search(int target) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < block_world[i].size(); j++) {
            if (block_world[i][j] == target)
                return i;
        }
    }

    return -1;
}

int clear_above(int target, int pile) {
    int temp = 0;
    while ((temp = block_world[pile].back()) != target) {
        block_world[temp].push_back(temp);
        block_world[pile].pop_back();
    }

    return pile;
}

void pile_over(int a, int b, int pile_a, int pile_b) {
    int idx = block_world[pile_b].size();
    int temp;
    while ((temp = block_world[pile_a].back()) != a) {
        block_world[pile_b].insert(block_world[pile_b].begin() + idx, temp);
        block_world[pile_a].pop_back();
    }
    block_world[pile_b].insert(block_world[pile_b].begin() + idx, a);
    block_world[pile_a].pop_back();
}

void print_blocks() {
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = 0; j < block_world[i].size(); j++) {
            cout << " " << block_world[i][j];
        }
        cout << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("./UVa101.fin", "r", stdin);
#endif

    int a, b;
    cin >> n; init();
    string s1, s2;

    while (cin >> s1 >> a >> s2 >> b) {
        int pile_a = search(a);
        int pile_b = search(b);

        if (pile_a == pile_b) continue;
        if (s1 == "move") clear_above(a, pile_a);
        if (s2 == "onto") clear_above(b, pile_b);
        pile_over(a, b, pile_a, pile_b);
    }

    print_blocks();
    return 0;
}