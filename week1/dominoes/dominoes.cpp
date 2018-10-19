#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n;
    cin >> n;

    int h = 0;
    vector<int> heights;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        heights.push_back(h);
    }

    int current_pos = 0;
    int max_shadow = 0;
    for (; current_pos < n; ++current_pos) {
        int this_shadow = current_pos + heights[current_pos];
        if (this_shadow > max_shadow) max_shadow = this_shadow;
        if (max_shadow <= current_pos + 1) break;
    }

    int toppled = 0;
    if (current_pos < n) {
        toppled = current_pos + 1;
    } else {
        toppled = n;
    }

    cout << toppled << endl;
}

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        test_case();
    }
    return 0;
}

