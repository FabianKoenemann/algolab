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
typedef vector<Point> pvec;

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
        homes.push_back(Point(x, y));
    }
    if (homes.size() <= 2) {
        //cout << "0\n";
        return;
    }
    Min_circle mc(homes.begin(), homes.end(), true);
    Traits::Circle c = mc.circle();
    Scalar min_r = c.squared_radius();
    cout << "before: " << ceil_to_double(CGAL::sqrt(min_r)) << "\n";
    // find the support point that is furthest away from the others
    int num_supp = mc.number_of_support_points();
    for (int i = 0; i < num_supp; ++i) {
        Point supp = mc.support_point(i);
        auto it = find(homes.begin(), homes.end(), supp);
        assert(it != homes.end());
        homes.erase(it);
        Min_circle mc2(homes.begin(), homes.end(), true);
        Traits::Circle c2 = mc2.circle();
        Scalar r_new = c2.squared_radius();
        //cout << "after removing point " << supp << ": " << ceil_to_double(CGAL::sqrt(r_new)) << "\n";
        if (r_new < min_r) {
            min_r = r_new;
        }
        homes.insert(it, supp);
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
