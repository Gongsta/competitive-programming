#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int b[n - 1];
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        vector<int> a(n, 0);

        for (int i = 0; i < 30; i++) {
            int curr_b = 1 << i;
            if ((curr_b & b[0]) != 0) {
                a[0] += curr_b;
            }
            for (int j = 0; j < n - 1; j++) {
                if ((curr_b & b[j]) != 0) {
                    a[j] |= curr_b;
                    a[j + 1] |= curr_b;
                }
            }
        }
        bool works = true;
        for (int i = 0; i < n - 1; i++) {
            if ((a[i] & a[i + 1]) != b[i]) {
                // cout << i << "not works" << (a[i] & a[i + 1]) << endl;
                works = false;
                break;
            }
        }
        if (works) {
            for (auto c : a) {
                cout << c << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
