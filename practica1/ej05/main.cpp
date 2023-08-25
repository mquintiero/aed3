#include <iostream>
/*
 * a) Es 2^n porque en cada paso recursivo llamamos a otros 2, y como hay n recursiones (porque recorremos la entrada) tenemos 2*2*2... n veces = 2^n
 *
 * b) Un ejemplo seria cuando tengo (1,1,0), (1,0,1) y (0,1,1) pues las 3 suman 2 ?
 *  a lo mejor se refiere que una vez que tengo por ejemplo (0,1) y quiero ver si agrego el proximo o no, pero puedo tener el resultado de (0,1)
 *  entonces ya sabes si tenes que agregar o no
 *
 *  d) La complejidad del inciso f era de O(2^n) mientras que esta es O(nk) pues es lo que nos lleva llenar la matriz (que es de n*k)
 *  Luego, acceder a estos es O(1) por lo que la complejidad solo esta dada nk
 *  Notar que en cada celda de la matriz tenemos un indefinido si todavia no lo calculamos,
 *  o tenemos el bool de ss(i,j) para todoo 0<=i,j<=n, es decir tenemos la respuesta para esa instancia
 *
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
