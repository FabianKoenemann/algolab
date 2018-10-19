#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <bits/stdc++.h>
using namespace CGAL;
using namespace std;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef K::Ray_2 Ray;
typedef K::Segment_2 Segment;
typedef K::FT Scalar;
typedef vector<Segment> Segvec;
typedef result_of<K::Intersect_2(K::Ray_2, K::Segment_2)>::type intersection_result;

void test_case(int n) {
    Ray beam;
    cin >> beam;

    Segvec walls;
    walls.reserve(n);
    for (int i = 0; i < n; ++i) {
        Point p1, p2;
        cin >> p1 >> p2;
        walls.push_back(Segment(p1, p2));
    }

    int i;
    for (i = 0; i < n; ++i) {
        if (do_intersect(walls[i], beam)) {
            cout << "yes\n";
            break;
        }
    }
    if (i == n) {
        cout << "no\n";
        return;
    }
}

int main() {
    if (numeric_limits<long>::digits < 51)
        throw range_error("Long is to short");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setiosflags(ios::fixed) << setprecision(0);
    for (int n; cin >> n && n > 0;)
        test_case(n);
    return 0;
}
