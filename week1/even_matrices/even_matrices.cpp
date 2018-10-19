#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n = 0;
    cin >> n;

    int m[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    int psums[n][n];
    for (int i = 0; i < n; ++i) {
        psums[i][0] = m[i][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            psums[i][j] = psums[i-1][j] + m[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            psums[i][j] += psums[i][j-1];
        }
    }

    int num_even = 0;
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i2 = i1; i2 < n; ++i2) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = j1; j2 < n; ++j2) {
                    int sum = psums[i2][j2];
                    if (i1 > 0) sum -= psums[i1-1][j2];
                    if (j1 > 0) sum -= psums[i2][j1-1];
                    if (i1 > 0 && j1 > 0) sum += psums[i1-1][j1-1];
                    if (sum % 2 == 0) num_even++;
                }
            }
        }
    }

    cout << num_even << endl;
}

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        test_case();
    }

    return 0;
}
