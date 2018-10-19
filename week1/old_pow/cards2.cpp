#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;

void test_case() {
    int n; cin >> n;
    int k; cin >> k;

    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x-k);
    }
    vector<int> p;
    p.reserve(n);
    p.push_back(v[0]);
    for (int i = 1; i < n; ++i) {
        p.push_back(p[i-1] + v[i]);
    }

    vector<int> pp;
    pp.reserve(n-1);
    for (int i = 1; i < n ; ++i) {
        pp.push_back(p[i] - p[i-1]);
    }

    for (auto x : pp) {
        cout << x << " ";
    }
    cout << endl << endl;


}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}
