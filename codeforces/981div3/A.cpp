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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = 0;
        bool sak_winner = true;
        for (int i = 1; i <= n * n + 1; i++) {
            if (i % 2 == 1) {
                x -= 2 * i - 1;
            } else {
                x += 2 * i - 1;
            }

            if (abs(x) > n) {
                if (i % 2 == 0) {
                    sak_winner = false;
                }
                break;
            }
        }

        if (sak_winner) {
            cout << "Sakurako" << endl;
        } else {
            cout << "Kosuke" << endl;
        }
    }

    return 0;
}
