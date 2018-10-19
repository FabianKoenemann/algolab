#include <cassert>
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

void test_case() {
    int n; cin >> n;
    int k; cin >> k;

    // vector of cumulative sums
    vector<int> s;
    s.reserve(n);
    for (int l = 0; l < n; ++l) {
        int v; cin >> v;
        s.push_back(v);
        if (l > 0)
            s[l] += s[l-1];
    }

    // a shortcut nested function for val(i, j)
    auto diff = [s, k, n](int i, int j) {
        assert(i <= j);
        assert(j < n);
        int sum = s[j];
        if (i > 0)
            sum -= s[i-1];
        return abs(sum - k);
    };

    int i = 0;
    int j = 0;
    int dlast = numeric_limits<int>::max();
    int dmin = dlast;
    int imin;
    int jmin;
    bool shrink = false;

    while (j < n) {
        cout << i << " " << j << "\n";
        int d = diff(i, j);
        if (d == 0) {
            cout << i << " " << j << "\n";
            return;
        }
        if (d < dmin) {
            dmin = d;
            imin = i;
            jmin = j;
        }

        int dj;
            dj = diff(i, j+1);
        int di;
        if (i < j) {
            di = diff(i+1, j);
        } else {
            di = d;
        }


        if (dj <= d) {
            j++;
        } else {
            i++;
        }
    }

    cout << imin << " " << jmin << "\n";
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}

