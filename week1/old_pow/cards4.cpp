#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>

using namespace std;

void test_case() {
    int n; cin >> n;
    int k; cin >> k;

    // vector of accumulative sums
    vector<int> s;
    s.reserve(n);
    // ordered map that can be used to log(n) search for closest fit
    map<int, int> m;

    for (int l = 0; l < n; ++l) {
        int v; cin >> v;
        // substract k here, so we can later search for same s
        // (at least I find that somehow more intuitive)
        s.push_back(v - k);
        if (l > 0)
            s[l] += s[l-1];
        cout << s[l] << " ";
    }
    cout << "/n/n";
        /* 
        // add (p[i], i) to map if not encountered before
        // (all ops on unordered_map are log(n) -> total n*log(n))
        if (!map.count(p[l])) {
            m[p[l]] = l;
        } else {
            // we have found an exact solution
            int i = m[p[l]].second + 1;
            int j = l;
            cout << i << " " << j << endl;
            return;
        }
    }

    // if the program arrives here, there is no exact solution
    // use the ordered property of map to find the closest match in log(n)
    int min = numeric_limits<int>::max();
    int i, j;
    for (int l = 0; l < n; ++l) {
        // squeeze value from both sides (equality would have terminited earlier)
        // both operations are log(n)
        auto l_it = m.lower_bound(p[l]);
        auto u_it = m.upper_bound(p[l]);

        // how far are we still away for both cases?
        int u_dist = abs(u_it->first - p[l]);
        int l_dist = abs(l_it->first - p[l]);

        if (l_dist 
    */
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}

