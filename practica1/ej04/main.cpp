#include <iostream>
#include "vector"
#include "limits"

using namespace std;

int evaluacion(vector<vector<int>> &d, vector<int> &pi){
    int res = 0;
    int n = pi.size();
    res += d[pi[n - 1]][pi[0]];
    for (int i = 0; i < n - 1; ++i) {
        res += d[pi[i]][pi[i + 1]];
    }
    return res;
}



vector<int> mejor_permutacion(vector<vector<int>> &d, vector<int> posibles, vector<int> &res, int min){
    vector<int> final;
    int n = d.size();
    int min2 = min;
    // caso base: cuando res sea de longitud n, ya estan todas las posibilidades
    if (res.size() == n){
        int eval = evaluacion(d, res);
        if (eval < min){
            min = eval;
            final = res;
            for (int i = 0; i < final.size(); ++i) {
                cout << final[i] << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (posibles[i] == 0){
                res.push_back(i);
                posibles[i] = 1;
                mejor_permutacion(d, posibles, res, min);
                posibles[i] = 0;
                res.pop_back();
            }
        }
    }
    return final;
}

int main() {
    vector<int> posibles(4);
    vector<vector<int>> d = {{0,1,10,10}, {10,0,3,15}, {21,17,0,2}, {3,22,30,0}};
    vector<int> res;
    int min = 3751276;
    vector<int> ans = mejor_permutacion(d, posibles, res, min);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
