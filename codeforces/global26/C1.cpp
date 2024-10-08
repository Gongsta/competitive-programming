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

/*
Things I have to convince myself:
- Is it always summing positive the correct answer?

You either always take the positive value, or you always take the negative value. FALSE
- You only need to take the absolute value once

-5 -5 -5 10
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
        ll sum = 0;
        ll idx = 0;
        ll min_val = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum < min_val) {
                idx = i;
                min_val = sum;
            }
        }
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (i == idx) {
                sum = abs(sum);
            }
        }
        cout << sum << endl;
    }

    return 0;
}
