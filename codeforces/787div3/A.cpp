#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int a,b,c,x,y;
    while (t--) {
        cin >> a >> b >> c >> x >> y;
        
        x -= a;
        y -= b;
        if (x > 0) {
            c -= x;
        }
        if (y > 0) {
            c -= y;
        }
        if (c < 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
