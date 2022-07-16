#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        double x;
        cin >> x;
        bool works = false;
        for (int a=1;a<=cbrt(x);a++) {
            if (abs(nearbyint(cbrt(x-pow(a,3))) - cbrt(x-pow(a,3))) < numeric_limits<double>::epsilon() && cbrt(x-pow(a,3) >= 1)) {
                works = true;
                break;
            }

        }

    if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
