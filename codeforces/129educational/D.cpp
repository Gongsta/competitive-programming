#include <bits/stdc++.h>

using namespace std;

set<int, greater<int> > ss;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n,x;
    cin >> n >> x;
    s = to_string(x);
    int y = 0;
    bool match = true;
    for (int i=0;i<s.length();i++) {
        ss.insert((int)s[i] - 48);
    }
    while (s.length() < n) {
        if ((*(ss.begin()) == 1) || (*(ss.begin()) == 0)) {
            match = false;
            break;
        } else {
            y++;
            x = stoi(s) * (*(ss.begin()));
            s = to_string(x);
            ss.clear();
            for (int i=0;i<s.length();i++) {
                ss.insert((int)s[i] - 48);
            }
        }

    }
    if (match) {
        cout << y << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
