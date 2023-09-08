#include <iostream>
#include "vector"

using namespace std;

int evaluar (vector<int> p, vector<int> disp){
    if (disp.empty()) return 0;
    int i = 1;
    int j = 0;
    int res = abs(p[0] - disp[0]);
    while (i < p.size() - 1){
        int izquierda = abs(p[i] - disp[j]);
        int derecha = j == disp.size() - 1 ? izquierda : abs(p[i] - disp[j + 1]);
        res += min(izquierda, derecha);
        i++;
        if (derecha < izquierda) j++;
    }
    res += abs(p[p.size() - 1] - disp[disp.size()-1]);
    return res;
}
vector<vector<int>> memo;
int undefined = -1;

int proveedurias (int k, vector<int>& p, int i, vector<int> &disp, vector<int> &res){
    if (i == p.size() && k > 0) return 487326;
    if (k == 0) return evaluar(p, disp);
    if (memo[k][i] == undefined) {
        disp.push_back(p[i]);
        int ponerP = proveedurias(k - 1, p, i + 1, disp, res);
        disp.pop_back();
        int noPonerP = proveedurias(k, p, i + 1, disp, res);
        if (ponerP <= noPonerP){
            res[res.size() - k] = p[i];
            memo[k][i] = ponerP;
        } else {
            memo[k][i] = noPonerP;
        }
    }
    return memo[k][i];
}


pair<int,vector<int>> proveedurias2 (int k, vector<int>& p, int i, vector<int> &disp){
    if (i == p.size() && k > 0) {
        vector<int> a;
        return make_pair(379218, a);
    }
    if (k == 0) return make_pair(evaluar(p, disp),disp);
    //pongo proveeduria en el lugar p[i]
    disp.push_back(p[i]);
    pair<int,vector<int>> ponerP = proveedurias2(k - 1, p, i + 1, disp);
    disp.pop_back();
    //ahora contemplo el caso donde no pongo nada en p[i]
    pair<int,vector<int>> noPonerP = proveedurias2(k, p, i + 1, disp);
    if (ponerP.first <= noPonerP.first) {
        pair<int, vector<int>> res = make_pair(ponerP.first, ponerP.second);
        return res;
    }  else {
        pair<int, vector<int>> res = make_pair(noPonerP.first, noPonerP.second);
        return res;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i) {
        int n, k;
        vector<int> disp;
        vector<int> disp2;
        vector<int> p;
        cin >> n;
        cin >> k;
        vector<int> res(k);
        memo = vector<vector<int>>(k + 1, vector<int>(n, undefined));
        for (int j = 0; j < n; ++j) {
            int tj;
            cin >> tj;
            p.push_back(tj);
        }
        int sol = proveedurias(k, p, 0, disp, res);
        pair<int,vector<int>> sol2 = proveedurias2(k, p,0, disp2);
        cout << sol << endl;
        for (int j = 0; j < res.size(); ++j) {
                cout << res[j] << " ";
            } cout << endl;

        cout << sol2.first << endl;
        for (int j = 0; j < sol2.second.size(); ++j) {
            cout << sol2.second[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
