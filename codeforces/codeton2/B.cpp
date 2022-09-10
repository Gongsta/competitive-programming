#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,x;
        cin >> n >> x;
        ll a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        ll min_v = a[0] - x;
        ll max_v = a[0] + x;
        int changes = 0;
        for (int i=1;i<n;i++) {
            if (a[i] <= (max_v+x) && a[i] >= (min_v-x)) {
                max_v = min(max_v, a[i]+x);
                min_v = max(min_v, a[i]-x);
            } 
            // else if (a[i] <= (max_v + x) && a[i] >= max_v) {
            //     min_v = max(min_v, a[i]-x);
            // } else if (a[i] >= (min_v - x) && a[i] <= min_v) {
            //     max_v = max(max_v, a[i]+x);
            // }
            else {
                changes++;
                min_v = a[i] - x;
                max_v = a[i] + x;
            }
        }
        cout << changes << endl;

        
      

    }

    return 0;
}
