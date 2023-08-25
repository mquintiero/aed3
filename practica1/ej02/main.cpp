#include <iostream>
#include "vector"
using namespace std;

/*
 * a) habria que hacer (n^2)! cuadrados
 *
 *
 */
bool is_valid(vector<vector<int>> &s) {
    int n = s.size();

    // Calculate magic number.
    int m = 0;
    for (int i = 0; i < n; i++) {
        m += s[i][0];
    }

    // Check rows and columns.
    for (int i = 0; i < n; i++) {
        int row = 0;
        int col = 0;
        for (int j = 0; j < n; j++) {
            row += s[i][j];
            col += s[j][i];
        }
        if (row != m || col != m) return false;
    }

    // Check diagonals.
    int diagonal1 = 0;
    int diagonal2 = 0;
    for (int i = 0; i < n; i++) {
        diagonal1 += s[i][i];
        diagonal2 += s[i][n - i - 1];
    }
    if (diagonal1 != m || diagonal2 != m) return false;

    return true;
}

int magic_square(vector<vector<int>> &square,int i, int j, vector<int> &av) {
    int n = square.size();
    int res = 0;
    if (j == n) return magic_square(square, i + 1, 0, av);
    if (i == n) return is_valid(square);

    for (int k = 0; k < n * n; ++k) {
        if (av[k] == 0){
            square[i][j] = k;
            av[k] = 1;
            res += magic_square(square, i, j + 1, av);
            av[k] = 0;
        }
    }
    return res;
}


int main() {
    vector<vector<int>> s = {{0,0,0}, {0,0,0}, {0,0,0}};
    int n = s.size();
    vector<int> av(n*n);
    cout << magic_square(s, 0, 0, av)<< endl;
    return 0;
}
