#include <iostream>
#include "vector"
#include "math.h"

using namespace std;


pair<int, int> cc (vector<int> &b, int i, int c){
    int n = b.size();
    if (c < 0) {
        return {0,0};
    } else if (i > n){
        return {10000,10000};
    } else {
        pair<int, int> rec = cc(b, i + 1, c - b[i]);
        return min({rec.first, 1 + rec.second}, cc(b, i + 1, c));
    }
}
int main() {
    vector<int> b = {2, 3, 5, 10, 20, 20};
    pair<int, int> c = cc(b,0,14);
    cout << c.first << " " << c.second << endl;
    return 0;
}
