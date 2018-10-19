#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

typedef vector<int> vec;

constexpr int dlimit = 100;

void test_case() {
    int n; cin >> n;
    
    vec x;
    x.reserve(n);
    for (int i = 0; i < n; ++i) {
        int xi; cin >> xi;
        x.push_back(xi);
    }
    sort(x.begin(), x.end());

    int i = 0, j = 0;
    int num_max = 0;
    int dmin = numeric_limits<int>::max();
    vec xmax;

    while (j < n) {
        int num = j - i + 1;
        int span = x[j] - x[i];

        if (span <= 2 * dlimit) {
            if (num >= num_max) {
                if (num > num_max) {
                    num_max = num;
                    dmin = numeric_limits<int>::max();
                    xmax.clear();
                }
                int d = span / 2;
                if (span % 2 == 1) ++d;
                if (d <= dmin) {
                    if (d < dmin) {
                        dmin = d;
                        xmax.clear();
                    }
                    int mid = (x[i] + x[j]) / 2; 
                    if (span % 2 == 0) {
                        xmax.push_back(mid);
                    } else {
                        int shift = 0;
                        if (x[i] == mid - d)
                            shift = -1;
                        xmax.push_back(mid + shift);
                        xmax.push_back(mid + 1 + shift);
                    }
                }
            }
        }

        if (span < 2 * dlimit) {
            ++j;
        } else if (span >= 2 * dlimit) {
            ++i;
        }
    }

    cout << num_max << " " << dmin << "\n";
    for (int xm : xmax) {
        cout << xm << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }
    return 0;
}
