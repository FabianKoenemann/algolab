#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> vvec;
typedef pair<int, int> ip;
typedef vector<ip> pvec;

int n;
int k;
pvec valids;

int attack(const int start, const int m) {
    if (m <= 0) return 0;
    if (start >= valids.size()) return -1;

    int i = valids[start].first;
    int j = valids[start].second;

    int vmax = -1;
    int next = start;
    while (++next < valids.size()) {
        int inext = valids[next].first;
        if (j < inext) {
            int vthis = j - i + 1;
            int vnext = attack(next, m - 1);
            if (vnext > -1)
                cout << "adding value for range " << i << ", " << j << ": " << vthis << endl;
                vmax = max(vmax, vnext + vthis);
        } else {
            vmax = max(vmax, attack(next, m));
        }
    }
    return vmax;
}

void test_case() {
    int m;
    cin >> n >> m >> k;
    vec v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int vi; cin >> vi;
        v.push_back(vi);
    }

    // pre-screening
    int i = 0, j = 0;
    int sum = v[0];
    valids = pvec();
    while (j < n) {
        if (sum == k) valids.push_back(make_pair(i, j));
        if (sum < k) sum += v[++j];
        else sum -= v[i++];
    }
    for (auto p : valids) {
        cout << "valid range: " << p.first << ", " << p.second << endl;
    }

    int atk = attack(0, m);

    if (atk > 0) {
        cout << atk << "\n";
    } else {
        cout << "fail" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        test_case();
    return 0;
}

