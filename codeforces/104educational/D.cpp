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
        ll count = 0;
        for (ll a=1;a<=n;a+=2) {
            ll b= (a * a - 1)/2;
            if (b + 1 > n) {
                break;
            } else {
                if (b > 0) {
                    count++;

                }
            }
        }
        cout << count << endl;
        

    }

    return 0;
}
