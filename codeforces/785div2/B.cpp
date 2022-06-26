#include <bits/stdc++.h>

using namespace std;

map<char, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        m.clear();
        string s;
        cin >> s;
        bool works = true;
        for (char x: s) {
            if (m.count(x)) {
                if (x != s[0]) {
                    works = false;
                    break;
                }
                m[x]++;
                if (m[x] > 2 && m.size() > 1) {
                    works = false;
                    break;
                }
            } else {
                m[x] = 1;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
