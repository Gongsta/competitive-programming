#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool works = true;
        int B_count = 0;
        int A_count = 0;
        for (int i=0;i<s.length();i++) {
            if (s[i] == 'B') {
                B_count++;
                if (A_count < B_count) {
                    works = false;
                    break;
                }
            } else {
                A_count++;
            }
        }
        if (B_count == 0 || s[s.length()-1] == 'A') {
            works = false;
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
