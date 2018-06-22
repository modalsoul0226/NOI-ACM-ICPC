//
// Created by xinze on 22/06/18.
//
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

typedef struct Matrix {
    int row;
    int col;

    Matrix(int row=0, int col=0) {
        this->row = row;
        this->col = col;
    }
} matrix_t;

void print_tab(const matrix_t *tab, const int& size) {
    for (int i = 0; i < size; i++)
        cout << "row: " << tab[i].row << " col: " << tab[i].col << endl; 
}

int main() {
#ifdef LOCAL
    freopen("./UVa442.fin", "r", stdin);
#endif

    matrix_t tab[26]; memset(tab, 0, sizeof(tab));

    int n; cin >> n; 
    // int size = n; cout << n << endl;
    while (n--) {
        char alph; cin >> alph;
        int row, col; cin >> row; cin >> col;
    
        tab[alph - 'A'] = matrix_t(row, col);
    }


    string s; getchar();
    while (getline(cin, s)) {
        stack<matrix_t> exp = stack<matrix_t>();

        int sum = 0;
        for (const char& ch: s) {
            
            if (isalpha(ch)) exp.push(tab[ch - 'A']);
            else if (ch == ')') {
                // Because of the rule: Matrix | (Expression Expression)
                if (exp.size() < 2) break;

                matrix_t b = exp.top(); exp.pop();
                matrix_t a = exp.top(); exp.pop();

                if (a.col != b.row) { sum = -1; break;}

                sum += a.row * a.col * b.col;
                exp.push(matrix_t(a.row, b.col));
            }
        }

        if (sum < 0) cout << "error\n";
        else cout << sum << endl;
    }

    return 0;
}