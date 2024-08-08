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

vector<ll> solve(vector<ll>& a, vector<ll>& b, vector<ll>& c, ll min_sum) {
    vector<ll> ans;  // 0-indexed
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < min_sum) {
            continue;
        }
        ans.push_back(0);
        ans.push_back(i);
        // binary search
        int j = lower_bound(b.begin() + i + 1, b.end(), min_sum + b[i]) - b.begin();
        if ((j >= b.size() - 1) || (c[c.size() - 1] - c[j] < min_sum)) {
            // try with other one
            j = lower_bound(c.begin() + i + 1, c.end(), min_sum + c[i]) - c.begin();
            if ((j >= c.size() - 1) || (b[b.size() - 1] - b[j] < min_sum)) {
                ans.clear();
            } else {
                ans.push_back(j + 1);         // b
                ans.push_back(c.size() - 1);  // b
                ans.push_back(i + 1);         // c
                ans.push_back(j);             // c
            }
        } else {
            ans.push_back(i + 1);
            ans.push_back(j);
            ans.push_back(j + 1);
            ans.push_back(c.size() - 1);
        }
        break;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        // Turn into prefix
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
            c[i] += c[i - 1];
        }
        ll min_total = ceil((double)a[n - 1] / 3.0);

        // try assigning a
        // Subsegments
        auto ans = solve(a, b, c, min_total);

        if (ans.empty()) {
            ans = solve(b, a, c, min_total);
            // cout << "solving with b first" << endl;

            if (ans.empty()) {
                ans = solve(c, a, b, min_total);
                // cout << "solving with c first" << endl;
                if (!ans.empty()) {
                    swap(ans[0], ans[2]);
                    swap(ans[1], ans[3]);
                    swap(ans[2], ans[4]);
                    swap(ans[3], ans[5]);
                }
            } else {
                swap(ans[0], ans[2]);
                swap(ans[1], ans[3]);
            }
        }
        if (ans.empty()) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
