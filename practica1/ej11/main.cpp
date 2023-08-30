#include <iostream>
#include "vector"

using namespace std;

vector<int> intercalar(vector<int> &v, int i, int w){
    //hago una recursion por cada posibilidad
    //suma
    intercalar(v, i + 1, w - v[i]);
    //multiplicacion
    intercalar(v, i + 1, w / v[i]);
    //potencia
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
