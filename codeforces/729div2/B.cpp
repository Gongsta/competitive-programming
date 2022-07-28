#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,a,b;
        cin >> n >> a >> b;
        bool works = false;
        if (a == 1) {
            if ((n-1) % b == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            ll tt = 1;
            while (tt <= n) {
                if (tt % b == n % b) {
                    works = true;
                    break;
                }
                tt *= a;
            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }


    }

    return 0;
}
