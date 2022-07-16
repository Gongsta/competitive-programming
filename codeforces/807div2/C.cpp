#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, c,q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        map<ll, ll> m;
        for (int i=0;i<n;i++) {
            m[i] = i;
        }
        ll curr = n;
        while (c--) {
            ll l,r;
            cin >> l >> r;
            l--;
            r--;
            if (m.count(l)) {
                m[curr] = m[l];
            } else {
                map<ll, ll>::iterator it = m.lower_bound(l);
                ll start = it->first;
                ll val = it->second;
                val -= (start - l);
                m[curr] = val;
            }
            if (m.count(r)) {
                m[curr + r - l] = m[r];
            } else {
                map<ll, ll>::iterator it = m.lower_bound(r);
                ll start = it->first;
                ll val = it->second;
                val -= (start - r);
                m[curr +  r - l] = val;
            }
            curr = curr + r - l + 1;        
        }
        while (q--) {
            ll k;
            cin >> k;
            k--;
            if (m.count(k)) {
                cout << s[m[k]] << endl;
            } else {
                map<ll, ll>::iterator it = m.lower_bound(k);
                ll start = it->first;
                ll val = it->second;
                val -= (start - k);
                cout << s[val] << endl;

            }
        }
    }

    return 0;
}
