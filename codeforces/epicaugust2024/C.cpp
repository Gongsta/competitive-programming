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
        long double x[n];
        long double y[n];
        long double xs, ys, xt, yt;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        cin >> xs >> ys >> xt >> yt;
        long double dist_st = sqrt(pow(xt - xs, 2) + pow(yt - ys, 2));
        cout << dist_st << endl;
        bool works = true;

        for (int i = 0; i < n; i++) {
            if (dist_st >= sqrt(pow(xt - x[i], 2) + pow(yt - y[i], 2))) {
                cout << setprecision(std::numeric_limits<double>::digits10 + 1) << i << " " << sqrt(pow(xt - x[i], 2) + pow(yt - y[i], 2)) << endl;
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
