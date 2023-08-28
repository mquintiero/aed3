#include <iostream>
#include "vector"
#include "math.h"

using namespace std;

pair<int, int> maxmin (pair<int, int> a, pair<int, int> b){
    if (a.first > b.first){
        return a;
    } else if (a.first == b.first) {
        pair<int, int> res = make_pair(a.first, b.second < a.second ? b.second : a.second);
        return res;
    } else {
        return b;
    }
}
vector<vector<pair<int,int>>> memo;
 // b) Complejidad O(2^n)
pair<int, int> cc (vector<int> &b, int i, int c){
    int n = b.size();
        if (c <= 0) {
            return {c,0};
        } else if (i > n){
            return {-10000,-10000};
        } else {
            pair<int, int> rec = cc(b, i + 1, c - b[i]);
        return maxmin({rec.first, 1 + rec.second}, cc(b, i + 1, c));
    }
}
/* c) Tengo superposicion de subproblemas cuando estoy en un mismo indice y me falta lo mismo por pagar
 *
 * d) Voy a utilizar una matriz de (i+1)*(c+1)
 */
// e) La complejidad sigue siendo O(2^n)
// Llamada recursiva??
pair<int, int> undefined = make_pair(309128,8793246);
pair<int, int> ccmemo (vector<int> &b, int i, int c){
    int n = b.size();
    if (c <= 0) {
        return {c,0};
    } else if (i > n){
        return {-10000,-10000};
    } else {
        if (memo[i][c] == undefined) {
            pair<int, int> rec = ccmemo(b, i + 1, c - b[i]);
            memo[i][c] = maxmin({rec.first, 1 + rec.second}, ccmemo(b, i + 1, c));
        }
        return memo[i][c];
    }
}

int main() {
    vector<int> b = {2, 3, 5, 10, 20, 20};
    int n = b.size();
    int c = 60;
    memo = vector<vector<pair<int, int>>>(
            n + 1,
            vector<pair<int, int>>(c + 1 ,undefined)
    );
    pair<int, int> calgo = ccmemo(b,0,c);
    cout << calgo.first << " " << calgo.second << endl;
    return 0;
}
