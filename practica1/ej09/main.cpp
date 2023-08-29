#include <iostream>
#include "vector"

using namespace std;

vector<vector<int>> memo;
int undefined = 30989037;

int vida_minima (vector<vector<int>> &A, int i, int j){
    // Este es el caso base en el que me pase de la casilla a la que queria llegar
    // Cuando llegue a la ultima casilla voy a hacer un llamado a la derecha y otro abajo asi que contemplo los 2 casos
    // y devuelvo 1 para ambos, que es la vida minima que puedo tener
    if (i == A.size()  && j == A[0].size() - 1) return 1;
    if (i == A.size() - 1  && j == A[0].size()) return 1;

    //Me falta el caso base donde alguna se fue de la casilla, como no quiero considerar esos casos, voy a poner
    // un numero grande, que nunca va a ganar en el min y por lo tanto no lo considero
    if (!(0 <= i && i <A.size() && 0<= j && j < A[0].size())) return 3287687;

    // Para cada casilla en la que caigo, la vida minima es la minima vida minima entre ir derecha o abajo
    // menos el valor de la casilla en la que estoy (si era una pocion voy a restarle a la vida minima porque ahora tengo
    // esa cantidad de vida para "tankear" lo que viene, si era una trampa, al ser negativo se va a sumar y
    // representa cuanda vida mas necesito para no morir en esa trampa)
    // En caso que ese numero sea menor a 0 (es decir, puedo sobrevivir incluso con vida negativa porque tengo
    // vida neta positiva en el camino), quiero que devuelva 1 pues es el minimo que se puede tener
    if (memo[i][j] == undefined) {
        int abajo = vida_minima(A, i + 1, j);
        int derecha = vida_minima(A, i, j + 1);
        int res = max(1, min(abajo, derecha) - A[i][j]);
        memo[i][j] = res;
    }
    return memo[i][j];
}
// La complejidad es O(n*m) que es lo que lleva completar la matriz pues una vez que esta completa los llamados son O(1)

int main() {
    vector<vector<int>> A = {
            {-2,  -3,  3},
            {-5, -10,  1},
            {10,  30, -5},
    };
    memo = vector<vector<int>>(3 ,vector<int>(3, undefined));
    int res = vida_minima(A,0,0);
    cout << res << endl;
    return 0;
}
