#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll l,r;
        cin >> l >> r;
        ll total = r - l;
        for (int i=1;i<10;i++) {
            total += r / (ll) pow(10, i) - l / (ll)pow(10,i);
        }
        cout << total << endl;

    }

    return 0;
}
