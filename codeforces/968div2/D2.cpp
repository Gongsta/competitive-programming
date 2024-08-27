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

int link[200001];

pair<int, int> mex(vector<int> &a) {
    vector<bool> f(a.size() + 2, 0);
    for (int i : a) {
        if (i <= (int)a.size()) {
            f[i] = 1;
        }
    }
    int mex1 = 0;
    int mex2 = 0;
    while (f[mex1]) {
        ++mex1;
    }
    mex2 = mex1 + 1;
    while (f[mex2]) {
        ++mex2;
    }
    return {mex1, mex2};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<int> v[n];
        ll max_mex = 0;
        for (int i = 0; i < n; i++) {
            ll l;
            cin >> l;
            max_mex = max(max_mex, l);
            for (int j = 0; j < l; j++) {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }

        for (int i = 0; i <= max_mex + 2; i++) {
            link[i] = i;
        }
        vector<int> adj[max_mex + 1];
        int link_num = 0;
        for (int i = 0; i < n; i++) {
            auto p = mex(v[i]);
            adj[p.first].push_back(p.second);
            link_num = max(link_num, p.first);
        }

        for (int i = max_mex; i >= 0; i--) {
            for (auto x : adj[i]) {
                link[i] = max(link[i], link[x]);
            }
            if (adj[i].size() > 1) {
                link_num = max(link_num, link[i]);
            }
        }
        ll ans = 0;
        for (int x = 0; x <= min(m, max_mex); x++) {
            ans += max(link[x], link_num);
        }
        ans += max(m * (m + 1) / 2ll - max_mex * (max_mex + 1) / 2ll, 0ll);

        cout << ans << endl;
    }

    return 0;
}
