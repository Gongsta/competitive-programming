#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll a[n];
        ll b[n];
        ll a_copy[n];
        ll b_copy[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            a_copy[i] = a[i];
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
            b_copy[i] = b[i];
        }
        map<ll, vector<ll>> m;
        sort(a_copy, a_copy+n);
        sort(b_copy, b_copy+n);
        for (int i=0;i<n;i++) {
            m[a_copy[i]].push_back(b_copy[i]);
        }
        for (int i=0;i<n;i++) {
            cout << m[a[i]].back();
            m[a[i]].pop_back();
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }


    }

    return 0;
}
