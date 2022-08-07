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
        map<int, int> total;
        map<int, int> m;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            total[a[i]]++;
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            m[a[i]]++;
            if (total[a[i]] - m[a[i]] >= 1) {
                ans = i+1;
            }
        }
        cout << ans << endl;

    }

    return 0;
}
