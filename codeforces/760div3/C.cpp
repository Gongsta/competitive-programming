#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        ll gcd_0 = a[0];
        ll gcd_1 = a[1];
        for (int i=3;i<n;i+=2) {
            gcd_1 = gcd(gcd_1, a[i]);
        }
        for (int i=2;i<n;i+=2) {
            gcd_0 = gcd(gcd_0, a[i]);
        }
        bool gcd_1_works = true;
        bool gcd_0_works = true;
        for (int i=0;i<n;i++) {
            if (i % 2 == 0) {
                if (a[i] % gcd_1 == 0) {
                    gcd_1_works = false;
                }
            } else {
                if (a[i] % gcd_0 == 0) {
                    gcd_0_works = false;
                }
            }
        }
        bool works = gcd_1_works || gcd_0_works;
        if (works) {
            ll val = gcd_1_works ? gcd_1 : gcd_0;
            cout << val << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
