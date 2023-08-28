#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

/*             -inf si c < 0 o c > j
 * b) f(j,c) = max(f(j-1,c-1) - p[j], f(j-1, c+1) + p[j], f(j-1,c))
 *
 * c) La respuesta es f(p.size() - 1,0) porque empezamos en el ultimo dia (porque vamos a hacer recursion hacia el primer dia)
 *    y con 0 asteroides porque si queremos maximizar la ganancia queremos haber vendido todos los que teniamos
 */

int undefined = 654654;
vector<vector<int>> memo;
int mgn (vector<int> &p, int j, int c){
    if (c < 0 || c > j + 1){ // tuve que cambiar este caso base porque como mi recursion llega hasta j<0, si no agregaba el +1, y c era 0 entonces me devolvia
        return -4762135;     // un resultado invalido con un caso valido
    }
    if (j < 0){
        return 0;
    }
    if (memo[j][c] == undefined) {
        int a = mgn(p, j - 1, c - 1) - p[j];
        int b = mgn(p, j - 1, c + 1) + p[j];
        int d = mgn(p, j - 1, c);
        memo[j][c] = max({a, b, d});
    }
    return memo[j][c];
}
// La matriz que voy a usar va a ser de n*n pues es la cantidad de combinaciones de dia y cantidad de asteroides
// La complejidad del algoritmo es
int main() {
    vector<int> p = {3,6,10};
    int n = p.size() - 1;
    memo = vector<vector<int>>(
            n + 1,
            vector<int>(n + 1, undefined)
    );
    int maxim = mgn(p, n, 0);
    cout << maxim << endl;
    return 0;
}
