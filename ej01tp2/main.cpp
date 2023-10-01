#include <iostream>
#include "vector"

using namespace std;
vector<vector<int>> tree_edges;
vector<int> estado; // 0 = No lo vi; 1 = Empece a ver; 2 = Termine de ver
vector<int> back_edges_con_extremo_inferior_en;
vector<int> back_edges_con_extremo_superior_en;
vector<vector<int>> aristas;

void dfs(int v, int p = -1) {
    estado[v] = 1;
    for (int u : aristas[v]) {
        if (estado[u] == 0) {
            tree_edges[v].push_back(u);
            dfs(u, v);
        } else if (u != p) {
            if (estado[u] == 1)
                back_edges_con_extremo_inferior_en[v]++;
            else // estado[u] == TERMINE_DE_VER
                back_edges_con_extremo_superior_en[v]++;
        }
    }
    estado[v] = 2;
}


vector<int> memo;
int cubren(int v, int p = -1) {
    if (memo[v] != -1) return memo[v];
    int res = 0;
    for (int hijo: tree_edges[v]) {
        if (hijo != p) {
            res += cubren(hijo, v);
        }
    }
    res -= back_edges_con_extremo_superior_en[v];
    res += back_edges_con_extremo_inferior_en[v];
    memo[v] = res;
    return res;
}
int puentes(int n){
    int cant_puentes = 0;
    for (int i = 0; i < n; i++) {
        if (cubren(i) == 0){
                cant_puentes++;
        }
    }
    return cant_puentes;
}

int main()
{
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        int bases, enlaces;
        cin >> bases; cin >> enlaces;
        vector<vector<int>> tree_edges;
        vector<int> estado(bases, 0);
        vector<vector<int>> aristas(bases);
        vector<pair<int, int>> ejes;
        vector<int> back_edges_con_extremo_inferior_en(bases, 0);
        vector<int> back_edges_con_extremo_superior_en(bases, 0);
        vector<int> memo(bases, -1);
        for(int j = 0; j < enlaces; j++){
            int u, v;
            cin >> u; cin >> v;
            ejes.push_back({u,v});
            aristas[u].push_back(v);
            aristas[v].push_back(u);
        }


    }

    return 0;
}
