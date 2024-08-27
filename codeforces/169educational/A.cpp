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
        int x[n];
        int cum_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            cum_sum += x[i];
        }
        int average = cum_sum / n;

        sort(x, x + n);
        int min_dist = x[1] - x[0];
        for (int i = 1; i < n; i++) {
            min_dist = min(min_dist, x[i] - x[i - 1]);
        }

        bool works = true;
        for (int i = 0; i < n; i++) {
            if (abs(average - x[i]) > min_dist || x[i] == average) {
                works = false;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
