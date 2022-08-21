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
        int odd = 0;
        if (n % 2 == 1) {
            odd += 1;
        }
        if (m % 2 == 1) {
            odd += 1;
        }
        odd %= 2;
        if (odd == 0) {
            cout << "Tonya" << endl;
        } else {
            cout << "Burenka" << endl;
        }

    }

    return 0;
}
