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
        ll a[n+1];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        int count = 0;
        for (ll i=1;i<=n;i++) {
            for (ll j=a[i] - i;j<=n;j+=a[i]) {
                if (j <= i) continue;
                if (i + j == a[i] * a[j]) {
                    count++;
                }
            }
        }
        cout << count << endl;

    }

    return 0;
}
