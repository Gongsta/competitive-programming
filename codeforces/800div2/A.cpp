#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        string s;
        while (a > 0 || b > 0) {
            if (a > 0) {
                s += '0';
                a--;
            }
            if (b > 0) {
                s += '1';
                b--;
            }
        }
        cout << s << endl;

    }

    return 0;
}
