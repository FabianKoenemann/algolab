#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> vecvec;

int take(const vec& v, vecvec& vv, const int l, const int r) {
    if (l > r) return 0;
    if (vv[l][r] == -1) {
        int ylhl = v[l] + take(v, vv, l+2, r);
        int ylhr = v[l] + take(v, vv, l+1, r-1);
        int yrhr = v[r] + take(v, vv, l, r-2);
        int yrhl = v[r] + take(v, vv, l+1, r-1);
        vv[l][r] = max(min(ylhl, ylhr), min(yrhr, yrhl));
    }
    return vv[l][r];
}

void test_case() {
    int n; cin >> n;

    vec v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int vi; cin >> vi;
        v.push_back(vi);
    }

    vecvec vv;
    vv.resize(n, vec(n, -1));
    cout << take(v, vv, 0, n-1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
        test_case();

    return 0;
}
