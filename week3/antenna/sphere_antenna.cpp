#include <CGAL/Cartesian.h>
#include <CGAL/Exact_rational.h>
#include <CGAL/Min_sphere_of_spheres_d.h>
#include <bits/stdc++.h>
using namespace CGAL;
using namespace std;

typedef CGAL::Exact_rational    FT;
//typedef double                  FT;
typedef CGAL::Cartesian<FT> K;
typedef CGAL::Min_sphere_of_spheres_d_traits_2<K, FT> Traits;
typedef CGAL::Min_sphere_of_spheres_d<Traits> Min_sphere;
typedef K::Point_2 Point;
typedef Traits::Sphere Sphere;

void test_case(int n) {
    vector<Sphere> S;
    S.reserve(n);
    for (int i = 0; i < n; ++i) {
        Point p;
        cin >> p;
        S.push_back(Sphere(p, 0));
    }
    Min_sphere ms(S.begin(), S.end());
    CGAL_assertion(ms.is_valid());
    pair<FT, FT> result = ms.radius();
    double a = to_double(result.first);
    double b = to_double(result.second);
    double t = to_double(ms.discriminant());
    double r = ceil(a + b * sqrt(t));
    std::cout << r << "\n";
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
