#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> vvec;

void test_case() {
    int n; cin >> n;

    vec m;
    m.reserve(n);
    for (int i = 0; i < n; ++i) {
        int mi; cin >> mi;
        m.push_back(mi);
    }

    vvec p;
    p.resize(n, vec());
    for (int i = 0; i < n; ++i) {
        p[i].reserve(m[i]);
        for (int j = 0; j < m[i]; ++j) {
            int pij; cin >> pij;
            p[i].push_back(pij);
        }
    }

    map<int, int> handmap;
    //vec hands(n, 0);
    for (int i = 0; i < n; ++i) handmap[p[i][0]] = i;
    int shortest = numeric_limits<int>::max();
    while (1) {
        int mini, maxi;
        int minp = numeric_limits<int>::max();
        int maxp = -1;
        for (int i = 0; i < n; ++i) {
            if (p[i][hands[i]] < minp) {
                minp = p[i][hands[i]];
                mini = i;
            }
            if (p[i][hands[i]] > maxp) {
                maxp = p[i][hands[i]];
                maxi = i;
            }
        }
        int length = p[maxi][hands[maxi]]
            - p[mini][hands[mini]] + 1;
        if (length < shortest) shortest = length;
        if (++hands[mini] >= m[mini]) break;
    }
    cout << shortest << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) test_case();
    return 0;
}
