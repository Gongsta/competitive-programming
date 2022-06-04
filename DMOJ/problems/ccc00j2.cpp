#include <bits/stdc++.h>

using namespace std;

bool compare(char a, char b) {
    if (a == '6') {
        return b == '9';
    } else if (a == '1') {
        return b == '1';
    } else if (a == '8') { 
        return b == '8';
    } else if (a == '9') {
        return b == '6';
    } else if (a == '0') {
        return b == '0';
    } else {
        return false;
    }
}
int check_val(int i) {
    if (i<10) {
        if (i == 1 || i == 8) {
            return 1;
        } else {
            return 0;
        }
    }
    string s = to_string(i);
    for (int i=0;i<=s.length()/2;i++) {
        if (i == s.length() - 1 - i) {
            if (s[i] != '0' && s[i] != '1' && s[i] != '8') {
                return 0;
            }

        } else if (!compare(s[i], s[s.length() - 1 - i])) {
            return 0;
        }

    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    
    int total = 0;
    cin >> m >> n;
    for (int i=m;i<=n; i++) {
       total += check_val(i);
    }
    cout << total << endl;

    return 0;
}
