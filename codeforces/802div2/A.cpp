#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;
        ll total = 0;
        for (ll i=1;i<=m;i++) {
            total+=i;
        }
        for (ll j=2;j<=n;j++) {
            total+=(j*m);
        }
        cout << total << endl;


    }

    return 0;
}
