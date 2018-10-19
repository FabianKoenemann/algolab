#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> boat;
typedef vector<boat> boatvec;
typedef set<int> endset;
typedef set<boat> boatset;

void test_case() {
    int n; cin >> n;

    boatvec b;
    b.reserve(n);
    endset e;
    boatset bs;
    for (int i = 0; i < n; ++i) {
        int l, p;
        cin >> l >> p;
        b.push_back(make_pair(l , p));
        int maxend = p + ((l % 2) ? l / 2 + 1 : l / 2);
        e.insert(maxend);
        bs.insert(make_pair(maxend, l));
    }

    for (boat p : bs) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    int num = 0;
    while (!e.empty()) {
        num++;
        auto next = lower_bound(e.begin(), e.end(), *e.begin());
        for (auto it = e.begin(); it != next; it = e.erase(it)) {
            for (int end : e) {
                cout << "end " << end << endl;
            }
            cout << endl;
        }
    }

    cout << num << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) test_case();
    return 0;
}
