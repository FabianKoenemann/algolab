#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> vvec;

int n;
int k;
vec v;
vvec vv;

int attack(int start, int attackers) {
   if (attackers <= 0) return 0;
   if (start >= n) return 0;
   //if (vv[start][attackers] != -1) return vv[start][attackers];

   int i = start, j = i;
   int defsum = v[i];
   while (j < n) {
       if (defsum == k) {
           int n_this = j - i + 1;
           int n_remain = attack(j + 1, attackers - 1);
           int n_alternative = attack(i + 1, attackers);
           //vv[start][attackers] = max(n_this + n_remain, n_alternative);
           //return vv[start][attackers];
           return max(n_this + n_remain, n_alternative);
       }
       if (defsum > k) {
           defsum -= v[i];
           ++i;
       } else {
           j++;
           defsum += v[j];
       }
   }
   return 0;
}


void test_case() {
    int m;

    cin >> n;
    cin >> m;
    cin >> k;

    v = vec();
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int vi; cin >> vi;
        v.push_back(vi);
    }

    vv = vvec(n, vec(m, -1));

    int atk = attack(0, m);

    if (atk) {
        cout << attack(0, m) << "\n";
    } else {
        cout << "fail" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }
    return 0;
}

