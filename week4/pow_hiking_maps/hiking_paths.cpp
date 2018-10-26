#include <bits/stdc++.h>
using namespace std;

//#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
using namespace CGAL;

typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Line_2 L;
typedef K::Triangle_2 T;

typedef vector<P> pvec;
typedef array<L, 3> lvec;

typedef vector<int> vec;
typedef vector<vec> vvec;

void test_case() {
    int m, n;
    cin >> m >> n;

    pvec p;
    p.reserve(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back(P(x, y));
    }

    vvec c(m-1, vec());
    for (int i = 0; i < n; ++i) {
        lvec l;
        array<P, 3> p1;
        for (int j = 0; j < 3; ++j) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            p1[j] = P(x1, y1);
            l[j] = L(p1[j], P(x2, y2));
        }
        array<bool, 3> ori;
        for (int j = 0; j < 3; ++j) {
            int other = (j+1) % 3;
            ori[j] = l[j].has_on_positive_side(p1[other]);
        }
        int prev = m + 1;
        for (int j = 0; j < m; ++j) {
            bool in = true;
            for (int k = 0; k < 3; ++k) {
                if (l[k].has_on_positive_side(p[j]) != ori[k]) {
                    in = false;
                    break;
                }
            }
            if (in) {
                if (prev == j-1)
                    c[j-1].push_back(i);
                prev = j;
            }
        }
    }

    // basically search snippets algorithm
    int k_min = n + 1;
    vec hands(m-1, 0);
    set<pair<int, int>> handmap;
    for (int j = 0; j < m - 1; ++j) handmap.insert(make_pair(c[j][hands[j]], j));
    while (1) {
        int cmin = handmap.begin()->first;
        int cmax = handmap.rbegin()->first;
        int minj = handmap.begin()->second;
        int maxj = handmap.rbegin()->second;
        int k = cmax - cmin + 1;
        if (k < k_min) k_min = k;
        if (++hands[minj] >= c[minj].size()) break;
        handmap.erase(handmap.begin());
        handmap.insert(make_pair(c[minj][hands[minj]], minj));
    }
    cout << k_min << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) test_case();
    return 0;
}
