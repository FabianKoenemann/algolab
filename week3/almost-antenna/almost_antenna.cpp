#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Min_circle_2.h>
#include <CGAL/Min_circle_2_traits_2.h>
#include <bits/stdc++.h>
using namespace CGAL;
using namespace std;

//typedef Exact_predicates_exact_constructions_kernel K;
//typedef Exact_predicates_inexact_constructions_kernel K;
typedef Exact_predicates_exact_constructions_kernel_with_sqrt K;
typedef Min_circle_2_traits_2<K> Traits;
typedef Min_circle_2<Traits> Min_circle;
typedef K::Point_2 Point;
typedef K::FT Scalar;
typedef list<Point> pvec;

double ceil_to_double(const Scalar& x) {
    double a = ceil(to_double(x));
    while (a < x) a += 1;
    while (a - 1 >= x) a -= 1;
    return a;
}

void test_case(int n) {
    pvec homes;
    for (int i = 0; i < n; ++i) {
        long x, y;
        cin >> x >> y;
        homes.push_back(Point(x, y));
    }
    if (n <= 2) {
        cout << 0 << "\n";
        return;
    }
    Min_circle mc(homes.begin(), homes.end(), true);
    assert(mc.is_valid());
    Traits::Circle c = mc.circle();
    Scalar min_r = c.squared_radius();
    int num_supp = mc.number_of_support_points();
    for (int i = 0; i < num_supp; ++i) {
        Point supp = mc.support_point(i);
        pvec homes2 = homes;
        auto it = find(homes2.begin(), homes2.end(), supp);
        assert(it != homes2.end());
        homes2.erase(it);
        Min_circle mc2(homes2.begin(), homes2.end(), true);
        assert(mc2.is_valid());
        Traits::Circle c2 = mc2.circle();
        Scalar r_new = c2.squared_radius();
        if (r_new < min_r) {
            min_r = r_new;
        }
    }
    cout << ceil_to_double(CGAL::sqrt(min_r)) << "\n";
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
