#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <vector>

// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int curr = 1e10;
    vector<int> a;
    int p = -1;
    for (int i = 1; i <= n; i++) {
        a.push_back(curr);
        curr /= 2;
        if (curr == 0 && p == -1) {
            p = i;
        }
        curr = max(1ll, curr);
    }
    for (int i = 0; i < p; i++) {
        int curr_sum = a[i];
        for (int j = i; j < n; j++) {
            curr_sum += a[j];
            if (a[j - 1] != 1 && curr_sum / 2 >= a[j]) {
                a[j - 1]--;
                curr_sum--;
            }
        }
    }

    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    // cout << "total pairs " << n * (n + 1) / 2 << endl;
    // int total = 0;
    // for (int i = 0; i < n; i++) {
    //     int curr_sum = 0;
    //     for (int j = i; j < n; j++) {
    //         curr_sum += a[j];
    //         if (a[i] > curr_sum / 2) {
    //             total++;
    //         }
    //     }
    // }
    // cout << total << endl;

    return 0;
}
