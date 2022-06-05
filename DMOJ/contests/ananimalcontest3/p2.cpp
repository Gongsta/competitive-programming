#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K,N,x;
    cin >> K >> N;
    x = 10;
    int a;
    bool haszero = false;
    while (N--) {
        cin >> a;
        if (a != 0) {
            x = min(a,x);
        } else {
            haszero = true;
        }
    }
    if (x == 10) {
        cout << -1 << endl;
    } else {
        if (!haszero) {
            while (K--) {
                cout << x;
            }
        } else {
            cout << x;
            for (int i=0;i<K-2;i++) {
                cout << 0;
            }
            if (K>=2) {
                cout << x;
            }
        }
        cout << endl;
    }
    

    return 0;
}
