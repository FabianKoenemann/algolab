#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef vector<double> vec;
typedef vector<vec> vvec;

vec p;
vvec vv;
int n;
int m;

double flip(int i, int k) {
    if (k <= 0) return 0; // broke
    if (k >= m) return 1; // won
    if (i >= n) return 0; // last day past
    if (vv[i][k] != -1) return vv[i][k];

    double pmax = 0.;
    for (int bet = 0; bet <= k; ++bet) {
        double ptot = 
            p[i] * flip(i+1, k + bet)
            +
            (1. - p[i]) * flip(i+1, k - bet);
        pmax = max(pmax, ptot);
    }
    vv[i][k] = pmax;
    return pmax;
}

void test_case() {
    cin >> n;
    int k; cin >> k;
    cin >> m;

    p = vec();
    p.reserve(n);
    for (int i = 0; i < n; ++i) {
        double pi; cin >> pi;
        p.push_back(pi);
    }

    vv = vvec(n, vec(m, -1));

    cout << fixed << setprecision(5);
    cout << flip(0, k) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }
    return 0;
}
