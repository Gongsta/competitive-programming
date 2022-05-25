#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, i=1;
    string I,P;
    cin >> t;
    while (t--) {
        cin >> I;
        cin >> P;

        int j=0;
        int total = 0;
        bool error = false;
        for (int i=0; i<I.length(); i++) {
            if (P[j] == I[i]) {
                j++;
            } else {
                while(P[j] != I[i]) {
                    j++;
                    total += 1;
                    if (j > P.length()) {
                        error = true;
                        break;
                    }
                }
                j++;
            }

            if (error) {
                break;
            }
        }

        if (error) {
            cout << "Case #" << i << ": IMPOSSIBLE" << endl;
        } else {
            total += (P.length() - j);
            cout << "Case #" << i << ": " << total << endl;
        }
        i += 1;
    }
}
