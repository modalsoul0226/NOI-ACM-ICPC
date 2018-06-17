#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// typedef vector<int> Pos;
// vector<string> ID_to_str;
// map<int,int> ID_to_pos;


// void bnf(const int& r, const int& c) {
//     map<string,V> tab; int c1;

//     for (int i = 0; i < r; i++) {
//         int found = 0; string line;
//         getline(cin, line); stringstream ss(line);
//         for (int j = 0; j < c; j++) {
//             string buf; getline(ss, buf, ',');
//             // cout << buf << endl;
//             V pos = {i, j}; vector<int> rows;
//             if (tab.count(buf) && tab[buf][1] == j) {
                
//             } else tab[buf] = pos;
//         }
//     }
//     cout << "YES\n";
// }

int main() {
#ifdef LOCAL
    freopen("./UVa1592.fin", "r", stdin);
#endif

    int r, c; 
    while (cin >> r && r != EOF) { 
        cin >> c;

        string schema[r][c];

        int found = 0; string line;
        getline(cin, line); 
        for (int i = 0; i < r; i++) {
            getline(cin, line); stringstream ss(line);
            for (int j = 0; j < c; j++) {
                getline(ss, schema[i][j], ',');
                // cout << buf[j] << endl;
            }
        }

        // for (int i = 0; i < r; i++)
        //     for (int j = 0; j < c; j++) cout << schema[i][j] << endl;

        for (int j = 0; j < c; j++) {
            for (int k = j + 1; k < c; k++) {
                map<string,int> str_to_row;
                for (int i = 0; i < r; i++) {
                    string cat = schema[i][j] + ',' + schema[i][k];
                    if (found) break;
                    if (str_to_row.count(cat)) {
                        found = 1; cout << "NO\n";
                        int row = str_to_row[cat];
                        cout << row + 1 << " " << i + 1 << endl;
                        cout << j + 1 << " " << k + 1 << endl;
                    } else {
                        str_to_row[cat] = i;
                    }
                }
            }
        }

        if (!found) cout << "YES\n";
    }

    return 0;
}