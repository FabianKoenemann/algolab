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
typedef vector<T> tvec;
typedef vector<L> lvec;
typedef vector<pair<P, P>> ppvec;
//typedef list<pair<P, P>> ppvec;

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
    ppvec pp;
    //pp.reserve(m-1);
    for (int i = 0; i < m - 1; ++i) {
        pp.push_back(make_pair(p[i], p[i+1]));
    }
    //random_shuffle(pp.begin(), pp.end());

    //tvec t;
    //t.reserve(n);
    vvec c(m-1, vec());
    int start = 0;
    for (int i = 0; i < n; ++i) {
        lvec l;
        l.reserve(3);
        for (int j = 0; j < 3; ++j) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            l.push_back(L(P(x1, y1), P(x2, y2)));
        }
        pvec trp;
        trp.reserve(3);
        for (int j = 0; j < 3; ++j) {
            for (int k = j + 1; k < 3; ++k) {
                auto o = intersection(l[j], l[k]);
                const P* op = boost::get<P>(&*o);
                trp.push_back(*op);
            }
        }
        //t.push_back(T(trp[0], trp[1], trp[2]));
        T t(trp[0], trp[1], trp[2]);
        auto it = pp.begin();
        //stack<ppvec::iterator> s;
        for (; it != pp.end(); ++it) {
            if (t.has_on_unbounded_side(it->first)) continue;
            if (t.has_on_unbounded_side(it->second)) continue;
            c[distance(pp.begin(), it)].push_back(i);
            //s.push(it);
            //start = j;
        }
        /*
        while (!s.empty()) {
            pp.erase(s.top());
            s.pop();
        }
        */
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
