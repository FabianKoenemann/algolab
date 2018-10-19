#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> vvec;

vvec t;
vec mem_rush;
vec mem_halt;
int n;

int halt(int pos);

int rush(int pos) {
    if (pos == n) return 0;
    if (mem_rush[pos] != -1) return mem_rush[pos];
    int min_remain = numeric_limits<int>::max();
    for (int next : t[pos]) {
        int remain = halt(next);
        min_remain = min(min_remain, remain);
    }
    mem_rush[pos] = ++min_remain;
    return mem_rush[pos];
}

int halt(int pos) {
    if (pos == n) return 0;
    if(mem_halt[pos] != -1) return mem_halt[pos];
    int max_remain = -1;
    for (int next : t[pos]) {
        int remain = rush(next);
        max_remain = max(max_remain, remain);
    }
    mem_halt[pos] = ++max_remain;
    return mem_halt[pos];
}

void test_case() {
    int m;
    cin >> n >> m;
    int r, b;
    cin >> r >> b;

    // transitions (1-based)
    t = vvec(n+1, vec());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
    }

    // init memoization vectors
    mem_rush = vec(n+1, -1);
    mem_halt = vec(n+1, -1);
    
    int min_steps_r = rush(r);
    int min_steps_b = rush(b);

    // in case of draw, meeple with even turn loses
    if (min_steps_r == min_steps_b)
        cout << ((min_steps_r % 2 == 0) ? 1 : 0);
    else
        // otherwise, the fastest is the winner
        if (min_steps_r < min_steps_b) cout << 0;
        else cout << 1;
    cout << "\n";

}

int main() {
    // IO optimizations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) test_case();
    return 0;
}
