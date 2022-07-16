#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,l,r;
        cin >> n >> l >> r;
        bool works = true;
        vector<ll> v;
        for (ll i=1;i<=n;i++) {
            ll val = l + (i - l % i);
            if (l % i == 0) {
                val = l;
            }
            if (l < i) {
                val = i;
            }
            if (val > r) {
                works = false;
                break;
            } else {
                v.push_back(val);
            }

        }
        if (!works) { 
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i=0;i<n;i++) {
                cout << v[i];
                if (i == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }

    }

    return 0;
}
