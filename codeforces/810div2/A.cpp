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
        for (int i=1;i<=n;i++) {
            if (i == n) {
                cout << 1;
            } else {
                cout << i+1;
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
