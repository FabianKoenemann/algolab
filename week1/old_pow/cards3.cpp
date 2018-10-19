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
        v.push_back(x);
    }
    vector<int> p;
    p.reserve(n);
    p.push_back(v[0]);
    for (int i = 1; i < n; ++i) {
        p.push_back(p[i-1] + v[i]);
    }

    // sorted map from partial sum -> index
    typedef pair<int, int> P;
    vector<P> m;
    m.reserve(n);
    for (int i = 0; i < n; ++i) {
        m.push_back(make_pair(p[i], i));
    }

    sort(m.begin(), m.end(), [](P a, P b){return a.first < b.first;});

    for (auto pp : m) {
        cout << pp.second << " ";
    }
    cout << endl << endl;

    int mindiff = numeric_limits<int>::max();
    int minidx;
    for (int i = 1; i < n; ++i) {
        int thisdiff = m[i].first - m[i-1].first;
        if (thisdiff < mindiff) {
            minidx = i;
            mindiff = thisdiff;
        }
    }

    int i1 = m[minidx].second;
    int i2 = m[minidx-1].second;

    int mini = min(i1, i2);
    mini += 1;

    int minj = max(i1,i2);

    cout << mini << " " << minj << endl;


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
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}
