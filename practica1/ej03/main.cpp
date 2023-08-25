#include <iostream>
#include "vector"

using namespace std;

//primero hago la funcion que haga la sumatoria que tengo que maximizar
int sumatoria(vector<vector<int>> &m, vector<int> &r){
    int res = 0;
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r.size(); ++j) {
            res += m[i][j];
        }
    }
    return res;
}

vector<int> res;
void matrix_sum(vector<vector<int>> &m,int i, int k, vector<int> &r){
    int n = m.size();
    int max_sum = 0;
    // caso base: cuanto mi subconjunto es de longitud k
    if (0 == k){
        if (sumatoria(m, r) > max_sum) {
            res = r;
        }
    } else if (i < n){
        // para el paso de backtracking quiero considerar cualquier indice que todavia no este en r
        // para eso voy a usar i, donde lo agrego o no lo agrego y pruebo
        // debido a esto tengo que chequear que i no se pase del tamaño de la matriz

        //primero pruebo sin agregar ese indice
        matrix_sum(m, i + 1, k, r);

        //ahora lo agrego
        r.push_back(i);
        matrix_sum(m, i + 1, k - 1, r);
        r.pop_back();
    }
}

int main() {
    int n = 4;
    vector<vector<int>> m = vector<vector<int>>(n);
    m[0] = {0,  10, 10, 1};
    m[1] = {10, 0,  5,  2};
    m[2] = {10, 5,  0,  1};
    m[3] = {1,  2,  1,  0};

    matrix_sum(m, 0, 3, res);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
