#include <iostream>

using namespace std;

void test_case() {

    int n;
    cin >> n;

    // sort input into 2D array
    int m[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    // precompute sums of blocks starting at (0,0)
    int p[n][n];
    // copy the first row
    for (int j = 0; j < n; ++j) {
        p[0][j] = m[0][j];
    }
    // "pull down"
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] = m[i][j] + p[i-1][j];
        }
    }
    // "pull right"
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            p[i][j] += p[i][j-1];
        }
    }

    // now we have a matrix of 2D partial sums
    int even_sums = 0;
    // choose two rows
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i2 = i1; i2 < n; ++i2) {
            // add them together and count even/odd
            int even = 0;
            int odd = 0;
            for (int j = 0; j < n; ++j) {
                int row_add = p[i1][j];
                if (i1 != i2) row_add += p[i2][j];
                if (row_add % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            even_sums += ((even - 1) * even) / 2 + (odd * (odd - 1)) / 2 + even;
        }
    }

    /*
    // make all combinations of start and end points and get the sum in O(1)
    int even_sums = 0;
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i2 = i1; i2 < n; ++i2) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = j1; j2 < n; ++j2) {
                    int sum = p[i2][j2];
                    if (i1 > 0) sum -= p[i1-1][j2];
                    if (j1 > 0) sum -= p[i2][j1-1];
                    if (i1 > 0 && j1 > 0) sum += p[i1-1][j1-1];
                    if (sum % 2 == 0) ++even_sums;
                }
            }
        }
    }

*/
    cout << even_sums << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) 
        test_case();
    return 0;
}

