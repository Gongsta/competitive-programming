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
        if (n % 3 == 0) {
            cout << n/3 << endl;
        } else if (n == 1){
            cout << 2 << endl;
        }  else if (n == 2) {
            cout << 1 << endl;

        } else if (n == 3) {
            cout << 1 << endl;

        } else {
            cout << n/3 + 1 << endl;

        }

    }

    return 0;
}
