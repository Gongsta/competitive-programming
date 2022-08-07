#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


string s,t;

// Okay, so you need to go from right to left... to try again

bool solve(int i, int j) {
    // cout << i << " " << j << endl;
    if (j == t.length() && i <=s.length()) return(s.length() - i) % 2 == 0;
    if (i >= s.length()) return false;
    if (s[i] == t[j]) {
        if (j == 0) {
            return solve(i+1, j+1) | solve(i+1,j);
        } else {
            return solve(i+1, j+1) | solve(i+2,j);
        }
    } else {
        if (j == 0) {
            return solve(i+1,j);
        } else {
            return solve(i+2, j);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        cin >> s >> t;
        if (solve(0,0) == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
