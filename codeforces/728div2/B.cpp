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
        vector<ll> a(n);
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int count = 0;
        for (ll i=1;i<=2*n;i++) {
            for (ll j=i+1;j<=2*n;j++) {
                if ((i * j) > 2 * n) break;
                a.find(i);
                a.find(j);
                if (i + j + 2== a[i] * a[j]) {
                    count++;

                }
            }
        }
        cout << count << endl;

    }

    return 0;
}
