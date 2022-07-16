#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    /*
    If even amount of negative, ans = multiply everything
    If odd, ans = one of the two sides
    */
    ll mod = 998244353;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];

        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        ll ans = a[0];
        ll temp = a[0];
        ll curr_sum = a[0];
        bool check = false;
        for (int i=0;i<n;i++) {
            if (i != 0) {
                curr_sum *= a[i];
                if (check) {
                    temp *= a[i];
                }
            }
            ans = max(ans, curr_sum);
            if (check) {
                ans = max(ans, temp);
            }
            if (curr_sum == 0) {
                curr_sum = 1;
            }
            if (temp == 0) {
                check = false;
            }
            if (a[i] < 0) {
                if (!check) {
                    check = true;
                    temp = 1;
                }
            }
        }
        ans %= mod;
        cout << ans << endl;
    }

    return 0;
}
