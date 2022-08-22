#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if (a * d == c * b) {
            cout << 0 << endl;
        } else if ((a*d == 0) || (c*b) == 0 || (a*d) % (c*b) == 0 || (c*b) % (a*d) == 0) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }

    }

    return 0;
}
