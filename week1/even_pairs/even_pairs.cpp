#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n = 0;
    cin >> n;

    int x = 0;
    int psum = 0;
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        psum += x;
        if (psum % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    int num_pairs = even + (even * (even - 1)) / 2 + (odd * (odd - 1)) / 2;

    cout << num_pairs << endl;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        test_case();
    }
    return 0;
}


