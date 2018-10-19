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
        //Point home;
        //cin >> home;
        homes.push_back(Point(x, y));
    }
    Min_circle mc(homes.begin(), homes.end(), true);
    Traits::Circle c = mc.circle();
    //Scalar r = CGAL::sqrt(c.squared_radius());
    Scalar sr = c.squared_radius();
    Scalar r = CGAL::sqrt(sr);
    std::cout << ceil_to_double(r) << "\n";
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
