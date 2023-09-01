#include <iostream>
#include "vector"

using namespace std;
//cargo cuando veo que no llego a la proxima estacion
pair<int, vector<int>> estaciones (vector<int> e, int c){
    vector<int> res = {e[0]};
    int est = 1; // carga en la estacion 0
    int actual = 0;
    int c_actual = c;
    for (int i = 0; i < e.size() - 1; ++i) {
        if (c_actual - (e[i + 1] - e[i]) < 0){
            c_actual = c;
            res.push_back(e[i]);
            est++;
        }
        c_actual -= e[i + 1] - e[i];

    }
    pair<int, vector<int>> sol = make_pair(est, res);
    return sol;
}

int main() {
    vector<int> e = {0, 3,4,5,9,14,15,20};
    int c = 5;
    pair<int, vector<int>> ans = estaciones(e, c);
    cout << ans.first << endl;
    for (int i = 0; i < ans.second.size(); ++i) {
        cout << ans.second[i] << " ";
    }
    return 0;
}
