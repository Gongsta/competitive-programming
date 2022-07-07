#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        reverse(a, a+n);
        ll count = 0;
        ll i=1;
        ll power = 1;
        while (i<n) {
            if (a[i] == a[0]) {
                i++;
            } else {
                count++;
                i += i;
            }
        }
        cout << count << endl;

    }

    return 0;
}
