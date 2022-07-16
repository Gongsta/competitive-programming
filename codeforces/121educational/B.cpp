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
        int double_i = -1;
        for (int i=s.length()-1;i>=1;i--) {
            if (s[i] - '0' + s[i-1] - '0' >= 10) {
                double_i = i-1;
                break;
            }
        }
        if (double_i !=-1) {
            string final;
            for (int i=0;i<double_i;i++) {
                final += s[i];
            }
            int num = s[double_i] - '0' + s[double_i+1] - '0';
            final += to_string(num);
            for (int i=double_i+2;i<s.length();i++) {
                final += s[i];
            }
            cout << final << endl;

        } else {
            string final;
            final += s[0] - '0' + s[1] - '0' + '0';
            for (int i=2;i<s.length();i++) {
                final += s[i];
            }
            cout << final << endl;
        }

    }

    return 0;
}
