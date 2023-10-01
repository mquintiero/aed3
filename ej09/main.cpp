#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

int vida_minima (vector<vector<int>> &terreno, int vida, int i, int j){
    if (i == terreno.size() && j == terreno[0].size()){
        return 3784646;
    } else if (i == terreno.size()){
        vida_minima(terreno, vida + terreno[i-1][j+1], i, j+1);
    } else if (j == terreno[0].size()){
        vida_minima(terreno, vida + terreno[i+1][j-1], i + 1, j);
    } else {
        int derecha = vida_minima(terreno, vida + terreno[i][j + 1], i, j + 1);
        int abajo = vida_minima(terreno, vida + terreno[i + 1][j], i + 1, j);
        return min({derecha, abajo, 1});
    }


}


int main() {
    vector<vector<int>> A = {{-2,-3,4}, {-5,-10,1}, {10,30,-5}};
    int sol = vida_minima(A, A[0][0], 0, 0);
    cout << sol << endl;
    return 0;
}
