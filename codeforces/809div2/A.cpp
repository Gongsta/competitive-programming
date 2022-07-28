#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        int a[n];
        string s;
        for (int i=0;i<m;i++) {
            s += 'B';
        }
        for (int i=0;i<n;i++) {
            cin >> a[i];
            a[i]--;
            if (a[i] < m-a[i] - 1) {
                if (s[a[i]] != 'A') {
                    s[a[i]] = 'A';
                } else {
                    s[m-a[i]-1] = 'A';
                }
            } else {
                if (s[m-a[i]-1] != 'A') {
                    s[m-a[i]-1] = 'A';
                } else {
                    s[a[i]] = 'A';
                }
            }
        }
        cout << s << endl;

    }

    return 0;
}
