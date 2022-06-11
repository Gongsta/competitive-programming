#include <bits/stdc++.h>

using namespace std;

/* If its 1111, you can't minimize. Or 0000

1011 -> 0111
0101010 -> 0000111

This was very painful, the small details really do make a difference, you really need to consider the edge case
of when there is only a single 1 in the middle. Because the "k" constraint makes it so you need to optimize
small details.
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        int n,k;
        cin >> n >> k;
        cin >> s;
        int total = 0;
        int first_one = -1;
        int last_one = -1;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '1') {
                if (first_one == -1) {
                    first_one = i;
                }
                last_one = i;
                 if (i == s.length() - 1) {
                    total += 1;
                } else if (i==0) {
                    total += 10;
                } else {
                    total += 11;
                }
            }
        }
        if (last_one == -1) { // No ones in the string, so already minimized
            cout << total << endl;
        } else {
            bool match_last = false;
            if (s[s.length() - 1] == '0') {
                if (k >= (s.length() - 1 - last_one)) {
                    if (last_one == 0) {
                        total -= 9;
                    } else {
                        total -= 10;
                    }
                    k -= s.length() - 1 - last_one;
                    match_last = true;
                }

            }
            if (s[0] == '0') {
                if (k >= (first_one) && first_one != s.length() -1) {
                    if (last_one == first_one) {
                        if (!match_last) {
                            total -= 1;
                        }
                    } else {
                        total -= 1;
                    }
                }
            }
            cout << total << endl;
        }
        
        
        
    }
    return 0;
}
