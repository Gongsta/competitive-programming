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
        map<int, int> m;
        int max_len = -1;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            if (m.count(a[i])) {
                max_len = max(max_len, n - i + m[a[i]]);
            } else {
                m[a[i]] = i;
            }
        }
        cout << max_len << endl;
        

    }

    return 0;
}
