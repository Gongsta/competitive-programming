#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    int x,y;
    while (t--) {
        cin >> x;
        int num_zeros_right = __builtin_ctz(x);
        if (num_zeros_right != 0) {
            if (__builtin_popcount(x) != 1) {
                y = pow(2, num_zeros_right);
            } else {
                y = pow(2, num_zeros_right) + 1;

            }
        } else {
            // We have to find the first 0
            if (x > 1) {
                y = 1;
            } else {
                y = 3;
            }

        }
        cout << y << endl;
        }

    return 0;
}
