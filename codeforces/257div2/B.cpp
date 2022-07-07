#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
Very difficult observation: Every 6th number is the same
*/

ll x, y, n;
ll mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> x >> y >> n;
    ll one = (x + mod) % mod;
    ll two = (y + mod) % mod;
    ll three;
    if (n > 6) {
        n = 6 + n % 6;
    }
    for (int i=3;i<=n;i++) {
        if (i != 3) {
            one = (two + mod) % mod;
            two = (three + mod) % mod;
        }
        three = (two - one) % mod;
        three = (three + mod) % mod;
    }
    if (n == 1) {
        cout << one << endl;
    } else if (n ==2 ) {
        cout << two << endl;
    } else {
        while (three < 0) {
            three += mod;
        }
    cout << three % mod << endl;

    }

    return 0;
}
