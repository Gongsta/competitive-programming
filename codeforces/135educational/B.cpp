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
            for (int i=1;i<=n-2;i++) {
                cout << i << " ";
            }
        } else {

        }
        cout << n -1 << " " << n << endl;

    }

    return 0;
}
