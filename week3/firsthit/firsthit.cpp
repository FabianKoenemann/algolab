#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <bits/stdc++.h>
using namespace CGAL;
using namespace std;

typedef Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 Point;
typedef K::Ray_2 Ray;
typedef K::Segment_2 Segment;
typedef K::FT Scalar;
typedef vector<Segment> Segvec;
typedef result_of<K::Intersect_2(K::Ray_2, K::Segment_2)>::type intersection_result;

double floor_to_double(const Scalar& x) {
    double a = floor(to_double(x));
    while (a > x) a -= 1;
    while (a + 1 <= x) a += 1;
    return a;
}

void adjust_clip(Segment& clip, const intersection_result& intersection) {
    if (const Point* p = boost::get<Point>(&*intersection))
            clip = Segment(clip.source(), *p);
    else if (const Segment* s = boost::get<Segment>(&*intersection))
        if (collinear_are_ordered_along_line(clip.source(), s->source(), s->target()))
            clip = Segment(clip.source(), s->source());
        else
            clip = Segment(clip.source(), s->target());
    else
        throw runtime_error("Impossible intersection type");
}

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
    random_shuffle(walls.begin(), walls.end());

    Segment clip(beam.source(), beam.point(1));

    int i;
    for (i = 0; i < n; ++i) {
        if (do_intersect(walls[i], beam)) {
            adjust_clip(clip, intersection(walls[i], beam));
            break;
        }
    }
    if (i == n) {
        cout << "no\n";
        return;
    }
    while (++i < n)
        if (do_intersect(walls[i], beam))
            adjust_clip(clip, intersection(walls[i], beam));
    Point first_hit = clip.target();
    cout << floor_to_double(first_hit.x()) << " " << floor_to_double(first_hit.y()) << "\n";
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
