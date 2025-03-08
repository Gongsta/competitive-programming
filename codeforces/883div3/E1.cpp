#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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

const int MAX_N = 1e6;
bool is_flake[MAX_N + 1];

void generate() {
    memset(is_flake, 0, sizeof(is_flake));
    for (int i = 2; i < 1000; i++) {
        int sum = 1 + i;
        int curr = i;
        for (int j = 0; j < MAX_N; j++) {
            curr = curr * i;
            sum += curr;
            if (sum > MAX_N) {
                break;
            }
            is_flake[sum] = true;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    generate();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (is_flake[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
