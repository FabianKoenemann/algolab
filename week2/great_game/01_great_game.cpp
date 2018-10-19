#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> transvec;

int go_back(int pos, const transvec& tr) {
    if (
    // at first just a test: go as far back as possible by taking the first option
    cout << pos << " -> ";
    
}

void test_case() {
    int n; cin >> n;
    int m; cin >> m;

    int r; cin >> r;
    int b; cin >> b;

    // vector of transitions pointing TO certain nodes
    transvec tr;
    // initialize with empty vectors
    tr.resize(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u; cin >> u;
        int v; cin >> v;
        // add a transistion from v to u (backwards)
        tr[v].push_back(u);
    }


}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
        test_case();
    return 0;
}
