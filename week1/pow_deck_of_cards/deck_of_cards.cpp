#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void test_case() {
    int n; cin >> n;
    int k; cin >> k;

    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int vi; cin >> vi;
        v.push_back(vi);
    }
    /*vector<int> s;
    s.reserve(n+1);
    s.push_back(0);
    for (int i = 1; i <= n; ++i) {
        s.push_back(v[i-1] + s[i-1]);
    }*/

    int i = 0, j = 0;
    int mini, minj;
    int min = numeric_limits<int>::max();

    int sum = v[0];
    while (j < n) {
        if (sum == k) {
            cout << i << " " << j << "\n";
            return;
        } 
        int d = abs(sum - k);
        if (d < min) {
            min = d;
            mini = i;
            minj = j;
        }
        if (sum < k) {
            j++;
            sum += v[j];
        } else {
            // means greater
            sum -= v[i];
            i++;
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = s[j+1] - s[i];
            int d = abs(sum - k);
            if (d == 0) {
                cout << i << " " << j << "\n";
                return;
            }
            if (d < min) {
                min = d;
                mini = i;
                minj = j;
            }
        }
    }*/

    cout << mini << " " << minj << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i= 0; i < t; ++i) {
        test_case();
    }
}
