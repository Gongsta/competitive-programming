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
        string a,b;
        cin >> n >> m;
        cin >> a >> b;
        bool works = false;
        for (int i=0;i<=n-m;i++) {
            if (b[0]==a[i]) {
                works = true;
                break;
            }
        }
        for (int i=n-m+1;i<n;i++) {
            if (b[i - (n-m)]!=a[i]) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
