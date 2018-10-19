#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

void test_case() {
    int n; cin >> n;
    int k; cin >> k;

    // minimum value and according indices seen so far
    int min_diff = numeric_limits<int>::max();
    int i = 0;
    int j = 0;

    // vector of cumulative sums
    vector<int> s;
    s.reserve(n);
    for (int l = 0; l < n; ++l) {
        int v; cin >> v;
        s.push_back(v);
        if (l > 0)
            s[l] += s[l-1];

        int target = s[l] - k;
        auto it = lower_bound(s.begin(), s.end(), target);
        // the above never returns s.end(), because k >= 0
        int found = *it;
        int diff = found - target ;
        int index = it - s.begin();
        if (diff < min_diff) {
            i = index + 1;
            j = l;
            min_diff = diff;
        }
        it = upper_bound(s.begin(), s.end(), target);
        if (it == s.end()) continue;
        found = *it;
        diff = found - target ;
        index = it - s.begin();
        if (diff < min_diff) {
            i = index + 1;
            j = l;
            min_diff = diff;
        }

    }
    cout << i << " " << j << "\n";
    //cout << min_sf << "\n\n";
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}

