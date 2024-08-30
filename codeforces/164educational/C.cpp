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
        string x;
        string y;
        cin >> x >> y;
        int n = x.size();
        string x_ans;
        string y_ans;
        for (int i = 0; i < n; i++) {
            // cout << x[i] << " " << y[i] << endl;
            if (i == 0) {
                x_ans += x[i];
                y_ans += y[i];
            } else {
                if (x_ans >= y_ans) {
                    x_ans += min(x[i], y[i]);
                    y_ans += max(x[i], y[i]);
                } else {
                    x_ans += max(x[i], y[i]);
                    y_ans += min(x[i], y[i]);
                }
            }
            // cout << x_ans << " " << y_ans << endl;
        }
        cout << x_ans << endl;
        cout << y_ans << endl;
    }

    return 0;
}
