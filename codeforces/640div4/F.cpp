#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int zeros, ones, twos;
        cin >> zeros >> ones >> twos;
        string s;
        if (zeros > 0) {
            s = "0";
            for (int i=0;i<zeros;i++) {
                s += "0";
            }
        }
        if (twos > 0) {
            if (zeros > 0) {
                ones--;
            }
            s += "1";
            for (int i=0;i<twos;i++) {
                s += "1";
            }
        }
        while (ones > 0) {
            if (s.empty()) {
                s += "1";
            }
            ones--;
            if (s.back() == '1') {
                s += "0";
            } else {
                s += "1";
            }
        }
        cout << s << endl;

    }

    return 0;
}
