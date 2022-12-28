#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /*
    1 (1 + 2) + 2 (2 + 3) + 3 (3 + 4) + ... + n (n + n +1) - n * (n + 1)
    
    sum(2i^2) + sum(i) - n^2 - n
    
    */
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll n1 = 1e9 +7;
        ll ans=((((n*(n+1))%n1)*(4*n-1))%n1*337)%n1;
        cout << ans << endl;
    }

    return 0;
}
