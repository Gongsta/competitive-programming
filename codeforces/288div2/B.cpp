#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    bool has_even = false;
    int max_even = 0;
    for (int i=0;i<s.length();i++) {
        if ((s[i] - '0')% 2 == 0) {
            has_even = true;
        }
    }
    bool swapped = false;
    for (int i=0;i<s.length();i++) {
        if ((s[i] - '0')% 2 == 0 && (s[i] < s.back())) {
            swap(s[i], s.back());
            swapped = true;
            break;
        }
    }
    if (!swapped) {
        for (int i=s.length()-1;i>=0;i--) {
            if ((s[i] - '0')% 2 == 0) {
                swap(s[i], s.back());
                break;
            }
        }
    }
    if (has_even) {
        cout << s << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
