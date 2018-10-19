#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> vvec;

vvec t;
int n, m;

int turn(int r, int b, int even, int player) {
    if (r == n) return 0;
    if (b == n) return 1;

    if (player == 0) {
        // sherlok triess to win
        if (even == 0) {
            // move red meeple
            for (int i = 0; i < t[r].size(); ++i) {
                int win = turn(t[r][i], b, 0, 1);
                if (win == 0) {
                    return 0;
                }
            }
        } else {
            // move black meeple
            for (int i = 0; i < t[b].size(); ++i) {
                int win = turn(r, t[b][i], 1, 1);
                if (win == 0) {
                    return 0;
                }
            }
        }
        return 1;
    } else {
        // moriarty tries to win
        if (even == 0) {
            // move black meeple
            for (int i = 0; i < t[b].size(); ++i) {
                int win = turn(r, t[b][i], 1, 0);
                if (win == 1) {
                    return 1;
                }
            }
        } else {
            // move red meeple
            for (int i = 0; i < t[r].size(); ++i) {
                int win = turn(t[r][i], b, 0, 0);
                if (win == 1){
                    return 1;
                }
            }
        }
        return 0;
        }
}
    
void test_case() {
    cin >> n >> m;
    int r, b;
    cin >> r >> b;

    t = vvec(n+1, vec());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
    }

    cout << turn(r, b, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) test_case();
    return 0;
}
        
