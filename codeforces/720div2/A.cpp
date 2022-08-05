#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll A,B;
        cin >> A >> B;
        ll C = lcm(A, B);
        if (C == A || C == A*A) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << A << " " << A * A << " " << C << endl;
        }
    }

    return 0;
}
