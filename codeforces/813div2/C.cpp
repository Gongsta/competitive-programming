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
        map<int, int> last;
        for (int i=0;i<n;i++) {
            last[a[i]] = i;
        }
        set<int> zeros;
        int last_i = -1;
        for (int i=1;i<n;i++) {
            if (a[i] < a[i-1]) {
                last_i = max(last_i, last[a[i-1]]);
            }
        }
        for (int i=0;i<=last_i;i++) {
            last_i = max(last_i, last[a[i]]);
            zeros.insert(a[i]);
        }
        cout << zeros.size() << endl;

    }

    return 0;
}
