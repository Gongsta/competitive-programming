#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int n;
        cin >> n;
        vector<ll> t_x;
        vector<ll> t_y;
        vector<ll> w_x;
        vector<ll> w_y;
        ll x,y;
        for (int i=0;i<n;i++) {
            cin >> x >> y;
            t_x.push_back(x);
            t_y.push_back(y);
        }
        int q;
        cin >> q;
        for (int i=0;i<q;i++) {
            cin >> x >> y;
            w_x.push_back(x);
            w_y.push_back(y);
        }
        
        ll ans = 0;
        ll squared_sum_x = 0;
        ll squared_sum_y = 0;
        ll sum_x = 0;
        ll sum_y = 0;
        for (int i=0;i<n;i++) {
            squared_sum_x += pow(t_x[i], 2);
            squared_sum_y += pow(t_y[i], 2);
            sum_x += t_x[i];
            sum_y += t_y[i];
        }
        for (int i=0;i<q;i++) {
            ans += n * pow(w_x[i], 2) + squared_sum_x - 2 * w_x[i] * sum_x;
            ans %= 1000000007;
        }
        for (int i=0;i<q;i++) {
            ans += n * pow(w_y[i], 2) + squared_sum_y - 2 * w_y[i] * sum_y;
            ans %= 1000000007;
        }
        
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
