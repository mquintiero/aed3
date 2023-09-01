#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

pair<int, vector<int>> suma(vector<int> v, int k){
    sort(v.begin(), v.end(), greater());
    int sum = 0;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        sum += v[i];
        res.push_back(v[i]);
    }
    pair<int, vector<int>> ans = make_pair(sum, res);
    return ans;
}

int main() {
    vector<int> v = {3,6,9,2,5};
    int k = 3;
    pair<int, vector<int>> sol = suma(v, k);
    cout << sol.first << endl;
    for (int i = 0; i < sol.second.size(); ++i) {
        cout << sol.second[i] << " ";
    }
    cout << endl;
    return 0;
}
