#include <iostream>
#include "vector"
using namespace std;

/*
 * a) soluciones candidatas:
 * a = (1,1,1)
 * a = (1,1,0)
 * a = (1,0,1) <-- valida
 * a = (0,1,1)
 * a = (0,0,1)
 * a = (0,1,0) <-- valida
 * a = (1,0,0)
 * a = (0,0,0)
 *
 * c) todos los vectores p de longitud menor a 3 van a ser soluciones parciales, pues cuando tiene longitud 3 ya es una solucion candidata
 *
 * d)                                   vacio
 *                  (0)                                         (1)
 *         (0,1)               (0,0)                (1,1)                    (1,0)
 *    (0,1,1)    (0,1,0)  (0,0,0)   (0,0,1)     (1,1,1)  (1,1,0)       (1,0,0)   (1,0,1)
 *
 * cada hijo de un nodo es la insercion de una de las 2 posibilidades (agregar un 0 o un 1)
 *
 * f) La complejidad es O(2^n)?
 *
 * g)
 *
 * i) Puedo ver si sumando la suma total de los elementos que todavia no considere puedo llegar a k, si no llegaba es al pedo seguir probando
 */

 // Implementacion
void subset_sum(vector<int> &c, int i, int targetSum, vector<int> &r){
    if (targetSum == 0){
        for (int j = 0; j < r.size(); ++j) {
            cout << r[j] << " ";
        }
        cout << endl;
        return;
    }
    if (i == c.size()){
        return;
    }

    if (targetSum < 0){
        return;
    }
    //chequeo sin considerar el elemento
    subset_sum(c, i + 1, targetSum, r);

    // ahora chequeo con el elemento
    r.push_back(c[i]);
    subset_sum(c, i + 1, targetSum - c[i], r);
    r.pop_back();

 }


int main() {
    vector<int> c = { 3, 34, 4, 12, 5, 2 };
    vector<int> r;
    subset_sum(c, 0, 9, r);
    return 0;
}
