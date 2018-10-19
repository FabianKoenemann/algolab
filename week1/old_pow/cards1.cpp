#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

void test_case() {
    int n; cin >> n;
    int k; cin >> k;

    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x - k);
    }

    int min_h = numeric_limits<int>::max();
    int min_f = numeric_limits<int>::max();

    int i_f = 0;

    // kedane's algorithm
    int j;
    for (j = 0; j < n; ++j) {
        if (min_h > 0) {
            min_h = v[j];
        } else {
            min_h += v[j];
        }
        if (min_f > min_h) {
            min_f = min_h;
            i_f = j;
        }
    }

        
    




    /*
    int dmin = numeric_limits<int>::max();
    int imin, jmin;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = p[j];
            if (i > 0)
                sum -= p[i-1];
            int d = abs(k - sum);
            if (d == 0) {
                cout << i << " " << j << endl;
                return;
            }
            if (d < dmin) {
                dmin = d;
                imin = i;
                jmin = j;
            }
        }
    }*/
    cout << i_f << " " << j << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}
