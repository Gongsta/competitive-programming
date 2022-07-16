#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    vector<ll> a_f;
    vector<ll> b_f;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (a_f.empty() || a[i] != a_f.back()) {
            a_f.push_back(a[i]);
        }
    }
    for (int i=0;i<m;i++) {
        cin >> b[i];
        if (b_f.empty() || b[i] != b_f.back()) {
            b_f.push_back(b[i]);
        }
    }

    int start = 0;
    ll ans = 0;
    for (int i=0;i<a_f.size();i++) {
        int power_pos = a_f[i];
        ll curr = abs(b_f[0] - power_pos);
        // Binary search
        int l = 0;
        int r = b_f.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == 0 || abs(b_f[mid] - power_pos) < abs(b_f[mid-1] - power_pos)) {
                curr = abs(b_f[mid]- power_pos);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = max(curr, ans);
    }
    cout << ans << endl;

    return 0;
}
