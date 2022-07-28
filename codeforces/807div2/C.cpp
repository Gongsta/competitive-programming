#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// This is an implementation problem but I thought I could solve it using a map

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
        ll curr = n;
        vector<ll> left(c+1);
        vector<ll> right(c+1);
        vector<ll> diff(c+1);
        left[0] = 0;
        right[0] = n;

        for(int i=1; i<=c; ++i){
            ll l, r; cin >> l >> r;
            l--; r--;
            left[i] = right[i-1];
            right[i] = left[i] + (r-l+1);
            diff[i] = left[i] - l;
        }
        while (q--) {
            ll k;
            cin >> k;
            k--;
            for (int i=c;i>0;i--) {
                if (k < left[i]) continue;
                else k -= diff[i];
            }
            cout << s[k] << endl;

        }
    }

    return 0;
}
