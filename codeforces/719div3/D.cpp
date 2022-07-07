#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        map<ll, ll> m;
        for (int i=0;i<n;i++) {
            a[i] = a[i] - (i+1);
            if (m.count(a[i])) {
                m[a[i]]++;
            } else {
                m[a[i]] = 1;
            }
        }
        ll total = 0; 
        for (auto x: m) {
            total += x.second * (x.second -1) / 2;
        }
        cout << total << endl;
        

    }

    return 0;
}
