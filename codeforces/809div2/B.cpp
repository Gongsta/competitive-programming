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
        int c[n];
        map<int, int> m;
        map<int, int> prev;
        for (int i=0;i<n;i++) {
            cin >> c[i];
            if (prev.count(c[i])) {
                m[c[i]] += (i - prev[c[i]]) % 2;
            } else {
                m[c[i]]++;
            }
            prev[c[i]] = i;
        }
        for (int i=1;i<=n;i++) {
            if (m.count(i)) {
                cout << m[i];
            } else {
                cout << 0;
            }
            if (i == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
