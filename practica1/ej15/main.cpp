#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

// solo hay que ordenar de menor a mayor
int main() {
    vector<int> p = {2,5,1};
    std::sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    return 0;
}
