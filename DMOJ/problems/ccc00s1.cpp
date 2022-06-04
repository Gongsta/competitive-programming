#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int total = 0;
    int q,a,b,c;
    cin >> q >> a >> b >> c;
    int start = 0;
    while (q--) {
        if (start % 3 == 0) {
            a++;
            total++;
            if (a % 35 == 0) {
                q += 30;
            }

        } else if (start % 3 == 1) {
            b++;
            total++;
            if (b % 100 == 0) {
                q += 60;
            }

        } else { // c
            c++;
            total++;
            if (c % 10 == 0) {
                q += 9;
            }

        }
        start++;
        
    }

    cout << "Martha plays " << total << " times before going broke." << endl;
    return 0;
}
