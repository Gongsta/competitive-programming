#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        int n;
        cin >> n;
        if (n % 5 == 0) {
            cout << "Case #" << i << ": " << n / 5 << endl;

        } else {
            cout << "Case #" << i << ": " << n / 5 + 1 << endl;
        }
    }

    return 0;
}
