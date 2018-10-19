#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<double> vec;

double max_prob_to_win(int i, const vec& p, int c, int m, int n) {
    if (c <= 0) return 0.; // broke
    if (c >= m) return 1.; // winner
    if (i >= n) return 0.; // time's up

    double pmax = 0.;
    for (int b = 0; b <= c; ++b) { 
        double total =
            p[i] * max_prob_to_win(i + 1, p, c - b, m, n) +
            (1. - p[i]) * max_prob_to_win(i + 1, p, c + b, m, n);
        pmax = max(pmax, total);
    }
    return pmax;
}

void test_case() {
    int n; cin >> n;
    int k; cin >> k;
    int m; cin >> m;

    // read in the probabilities
    // pv will hold the WINNING chances
    vector<double> pv;
    pv.reserve(n);
    for (int i = 0; i < n; ++i) {
        double pi; cin >> pi;
        if (pi >= .5) {
            pv.push_back(pi);
        } else {
            pv.push_back(1 - pi);
        }
    }

    double P = max_prob_to_win(0, pv, k, m, n);
    
    cout << fixed << setprecision(5);
    cout << P << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }
    return 0;
}
