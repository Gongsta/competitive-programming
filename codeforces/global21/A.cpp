#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,z;
        cin >> n >> z;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int max_val = 0;
        for (int i=0;i<n;i++) {
            int val = a[i] | z;
            max_val = max(val, max_val);
        }
        cout << max_val << endl;
        

    }

    return 0;
}
