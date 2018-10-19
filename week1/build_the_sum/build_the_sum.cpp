#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    vector<int> v;

    int n = 0;
    cin >> n;

    int a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.push_back(a);
    }

    int sum = 0;
    for (auto a : v) {
        sum += a;
    }

    cout << sum << endl;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        test_case();
    }
    return 0;
}
