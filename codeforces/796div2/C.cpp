#include <bits/stdc++.h>

using namespace std;

map<char, int> m;

// https://codeforces.com/problemset/problem/1688/C

/* 
Such a simple solution for such a complicated problem.

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    int n;
    string s;
    while (T--) {
        cin >> n;
        n *= 2;
        n++;
        m.clear();
        while (n--) {
            cin >> s;
            for (auto c: s) {
                if (m.count(c)) {
                    m[c] += 1;
                } else {
                    m[c] = 1;
                }
            }
        }
        for (auto x: m) {
            if (x.second % 2 == 1) {
                cout << x.first << endl;
                break;
            }
        }
    }
    return 0;
}
