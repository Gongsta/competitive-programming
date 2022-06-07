#include <bits/stdc++.h>

using namespace std;

/*
Observations:
1. If current == previous (1 or 0), only one of the two can be lying
    000 -> 1st guy is lying, first guy
    111
    
    When there is a change, both people are suspects
    01 -> 0 and 1 can't be both lying. 0 can say he didn't see it but it was actually there before and stole it. 1 can lie by saying he saw it, but no if 1 is lying, 0 can't be lying so 0 should have said 1??
        -> 01 is an impossible scenario in this sense
    10 -> 1 could have stolen it but say it was still there. 0 could say that is was gone but he actually took it.
    
    ? -> makes you automtically suspect?
    
    As soon as you have a 0 and 1, you can bound the problem

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    string s;
    while (t--) {
        int total = 0;
        cin >> s;
        char start_state = s[s.length()-1];
        bool has_zero = false;
        bool has_one = false;
        if (start_state == '0') {
            has_zero = true;
            total = s.length();
        } else if (start_state == '1') {
            has_one = true;
            total = 1;
        } else {
            total = 1;
        }
        for (int i=s.length()-2;i>=0;i--) {
            if (s[i] == '0') {
                total = i+1;
                has_zero = true;
            } else if (s[i] == '1') {
                if (has_zero) {
                    total = abs(total - i);
                    break;
                } else if (!has_one) {
                    total++;
                    has_one = true;
                }
            } else if (s[i] == '?') {
                if (!has_zero && !has_one) {
                    total++;
                }
            }
        }
        if (s.length() == 1) {
            cout << 1 << endl;

        } else {
            cout << total << endl;
        }

    }

    return 0;
}
