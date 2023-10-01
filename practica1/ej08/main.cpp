#include <iostream>
#include "vector"

using namespace std;

/*
 * b) f(C, i, j)= min(
 */

bool noHayCortes (vector<int> c, int i, int j){
    for (int k = i; k < j; ++k) {
        if (c[k] == 1){
            return false;
        }
    }
    return true;
}
vector<vector<int>> memo;
int undefined = -1;
int minCosto (vector<int> &c, int i, int j) {
    if (noHayCortes(c, i, j)){
        return 0;
    }
    int minim = 783264;
    if (memo[i][j] == undefined){
        for (int k = i; k <= j; ++k) {
            if (c[k] == 1) {
                c[k] = 0;
                int res = (j - i + 1) + minCosto(c, i, k) + minCosto(c, k + 1, j);
                c[k] = 1;
                if (res < minim) {
                    minim = res;
                }
                memo[i][j] = minim;
            }
        }
    }
    return memo[i][j];
}

int main() {
    vector<int> c = {0,1,0,1,0,0,1,0,0,0};
    int n = c.size();
    memo = vector<vector<int>>(n, vector<int>(n, undefined));
    int sol = minCosto(c, 0, n - 1);
    cout << sol << endl;
    return 0;
}
