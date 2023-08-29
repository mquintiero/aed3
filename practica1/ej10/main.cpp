#include <iostream>
#include "vector"

using namespace std;

vector<vector<int>> memo;
int undefined = -1;
int cajas (vector<int> &w, vector<int> &s, int i, int k){ // k va a ser cuanto peso mas puedo poner, por lo que se actualiza cada recursion con el valor menor
    // si ya contemple todas las cajas devuelvo 0 (no poner mas cajas)
    if (i == w.size()) return 0;
    // si el peso que me queda por poner es 0 devuelvo 0 pues no puedo poner mas cajas
    if (k == 0) return 0;

    int res = 0; // inicializo la respuesta en 0 cajas

    if (w[i] <= k) {
        // pongo la caja i, actualizando k a el minimo entre el peso que me quedaba menos el que acabo de poner y el peso de la caja nueva
        int poner_caja = 1 + cajas(w, s, i + 1, min(k - w[i], s[i]));
        // ahora pruebo sin poner la caja i
        int no_poner = cajas(w, s, i + 1, k);
        res = max(poner_caja, no_poner);
    } else { // si la caja i excede el peso que puedo soportar, no pongo nada y paso a la siguiente caja
        res = cajas(w, s, i + 1, k);
    }
    return res;
}

int cajastd (vector<int> &w, vector<int> &s, int i, int k){ // k va a ser cuanto peso mas puedo poner, por lo que se actualiza cada recursion con el valor menor
    // si ya contemple todas las cajas devuelvo 0 (no poner mas cajas)
    if (i == w.size()) return 0;
    // si el peso que me queda por poner es 0 devuelvo 0 pues no puedo poner mas cajas
    if (k == 0) return 0;

    if (memo[i][k] == undefined) {
        if (w[i] <= k) {
            // pongo la caja i, actualizando k a el minimo entre el peso que me quedaba menos el que acabo de poner y el peso de la caja nueva
            int poner_caja = 1 + cajastd(w, s, i + 1, min(k - w[i], s[i]));
            // ahora pruebo sin poner la caja i
            int no_poner = cajastd(w, s, i + 1, k);
            memo[i][k] = max(poner_caja, no_poner);
        } else { // si la caja i excede el peso que puedo soportar, no pongo nada y paso a la siguiente caja
            memo[i][k] = cajastd(w, s, i + 1, k);
        }
    }
    return memo[i][k];
}

int max2 (vector<int> list){
    int max = list[0];
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] > max) {
            max = list[i];
        }
    }
    return max;
}
int main() {
    vector<int> w = {19, 7, 5, 6, 1};
    vector<int> s = {15, 13, 7, 8, 2};
    int n = w.size();
    memo = vector<vector<int>>(n, vector<int>(max2(w),undefined));
    int sol = cajas(w, s, 0, max2(w));
    int soltd = cajastd(w, s, 0, max2(w));
    cout << sol << endl;
    cout << soltd << endl;
    return 0;
}
