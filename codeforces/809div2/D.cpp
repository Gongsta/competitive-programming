#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        ll a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        ll min_val = a[0];
        if (k >= a[n-1]) {
            cout << 0 << endl;
        } else {
            ll ans = 0;
            for (int i=1;i<n;i++) {
                ll l = 1;
                ll r = k;
                while (l <= r) {
                    ll mid = (l+r) / 2;
                    if (a[i]/mid - min_val < curr_min) {

                    }
                }
                max_val = max(max_val, a[i]);
            }
            cout << ans << endl;

        }

    }

    return 0;
}
