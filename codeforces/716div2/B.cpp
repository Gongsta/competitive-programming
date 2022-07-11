#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        // k represents the number of bits you can have
        ll mod = 1e9+7;
        ll total = 1;
        for (int i=0;i<k;i++) {
            total *= n;
            total %= mod;
        }
        cout << total << endl;

    }

    return 0;
}
