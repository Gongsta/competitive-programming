#include <bits/stdc++.h>

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
        bool works = false;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (i > 0 && a[i] < a[i-1]) {
                works = true;
            }
        }
        if (works)  {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
