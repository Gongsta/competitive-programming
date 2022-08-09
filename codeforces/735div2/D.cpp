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
        if (n == 1) {
            cout << "a" << endl;

        } else {
            for (int i=0;i<n/2;i++) {
                cout << "a";
            }
            if (n% 2 == 0) {
                cout << "b";
            } else {
                cout << "bc";
            }
            for (int i=0;i<n/2-1;i++) {
                cout << "a";
            }
            cout << endl;

        }

    }

    return 0;
}
