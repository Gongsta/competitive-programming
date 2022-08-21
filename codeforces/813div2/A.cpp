#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int p[n];
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> p[i];
            a[i] = p[i];
        }
        sort(a, a+n);
        set<int> s;
        for (int i=0;i<k;i++) {
            s.insert(a[i]);
        }
        int ans = 0;
        for (int i=0;i<k;i++) {
            if (!s.count(p[i])) {
                ans++;
            }
        }
        cout << ans << endl;

    }

    return 0;
}
