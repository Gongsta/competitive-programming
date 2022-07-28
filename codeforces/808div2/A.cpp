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
        bool works = true;

        for (int i=1;i<n;i++) {
            if (a[i] % a[0] != 0 || a[i] < a[0]) {
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
