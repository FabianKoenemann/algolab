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
    vec hands(n, 0);
    for (int i = 0; i < n; ++i) handmap[p[i][hands[i]]] = i;
    int shortest = numeric_limits<int>::max();
    while (1) {
        int pmin = handmap.begin()->first;
        int pmax = handmap.rbegin()->first;
        int mini = handmap.begin()->second;
        int maxi = handmap.rbegin()->second;
        int length = pmax - pmin + 1; 
        if (length < shortest) shortest = length;
        if (++hands[mini] >= m[mini]) break;
        handmap.erase(pmin);
        handmap[p[mini][hands[mini]]] = mini;
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
