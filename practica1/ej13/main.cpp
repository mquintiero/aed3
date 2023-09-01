#include <iostream>
#include "vector"

using namespace std;

int parejas(vector<int> p1, vector<int> p2){
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < p1.size()){
        if (abs(p1[i] - p2[j]) <= 1){
            res++;
            i++;
            j++;
        } else if (p1[i] < p2[j]){
            i++;
        } else {
            j++;
        }
    }
    return res;
}

int main() {
    vector<int> p1 = {1, 2, 4, 6};
    vector<int> p2 = {1, 5, 5, 7, 9};
    int sol = parejas(p1, p2);

    vector<int> p3 = {1, 1, 1, 1, 1};
    vector<int> p4 = {1,2,3};
    int sol2 = parejas(p3, p4);
    cout << sol << endl;
    cout << sol2 << endl;
    return 0;
}
