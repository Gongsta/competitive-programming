#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll hc,dc,hm,dm;
        cin >> hc >> dc >> hm >> dm;
        ll k,w,a;
        cin >> k >> w >> a;
        
        ll attacks = ceil((long double)(hm)/(long double)(dc));
        ll defenses = ceil((long double)(hc)/(long double)(dm));
        if (attacks <= defenses) {
            cout << "YES" << endl;
        } else {
            bool works = false;
            for (ll i=0;i<=k;i++) {
                attacks = ceil((long double)(hm)/(long double)(dc + i * w));
                defenses = ceil((long double)(hc + (k-i) * a)/(long double)(dm));
                if (attacks <= defenses) {
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

    }

    return 0;
}
