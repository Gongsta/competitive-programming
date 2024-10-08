#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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

/*
8 7 9

8 7 7
7 7 6
7 6 5
6 7

lag = 3
5 7 5

7 5 7

lag = 3
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = a[n - 1];
        ll lag = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                a[i] = max(a[i + 1], a[i] - lag);
                if (a[i] == a[i + 1]) {
                    lag += 1;
                }
            } else {
                lag += a[i + 1] - a[i] + 1;
            }
            ans = max(ans, lag + a[i]);
            // cout << lag << " " << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
