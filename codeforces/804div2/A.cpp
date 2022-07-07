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
        if (n % 2 == 1) {
            cout << -1 << endl;
        } else {
            cout << "0 " << n/2 << " " << n / 2 << endl;
        }
    }

    return 0;
}
