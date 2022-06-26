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
        bool one;
        if (n % 3 == 0 || n % 3 == 2) {
            one = false;
        } else {
            one = true;
        }
        int sum = 0;
        if (n <= 2) {
            cout << n << endl;
        } else {
            while (sum < n) {
                if (one) {
                    sum++;
                } else {
                    sum += 2;
                }
                if (one) {
                    cout << "1";
                } else {
                    cout << "2";
                }
                one = !one;

            }
            cout << endl;
        }
    }

    return 0;
}
