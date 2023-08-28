#include <iostream>
#include "vector"

using namespace std;

/*
 * b) f(C, i, j)= min(
 */

bool noHayCortes (vector<int> c, int i, int j){
    for (int k = i; k < j + 1; ++k) {
        if (c[k] == 1){
            return false;
        }
    }
    return true;
}

int minim = 783264;
int minCosto (vector<int> &c, int i, int j) {0;
    if (noHayCortes(c, i, j)){
        return 0;
    }
    int minim = 783264;
    for (int k = i; k <= j; ++k) {
        if (c[k] == 1){
            c[k] = 0;
            int res = (j - i) + minCosto(c, i, k) + minCosto(c, k, j);
            c[k] = 1;
            if (res < minim){
                minim = res;
            }
        }
    }
    return minim;
}

int main() {
    vector<int> c = {0,1,0,1,0,0,1,0,0,0};
    int n = c.size();
    int sol = minCosto(c, 0, n - 1);
    cout << sol << endl;
    return 0;
}
