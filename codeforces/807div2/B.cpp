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
        ll total = 0;
        bool number_seen = false;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (i != n -1) {
                total += a[i];
                if (a[i] != 0) {
                    number_seen = true;
                }
                if (number_seen && a[i] == 0) {
                    total++;
                }
            }
        }
        cout << total << endl;
    }

    return 0;
}
