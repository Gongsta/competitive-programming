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
        ll a[n];
        ll total = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }

        for (int i=0;i<n;i++) {
            int zeros = 0;
            for (int j=i;j<n;j++) {
                if (a[j] == 0) {
                    zeros++;
                }
                total += (j-i+1) + zeros;
            }
        }

        cout << total << endl;
    }
        
    return 0;
}
