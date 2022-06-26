#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string val;
        cin >> val;
        string final;
        for (int i=0;i<val.length();i++) {
            final += ('0' + (9 - (val[i]-'0')));
        }
        if (final[0] == '0') {
            int increment = 0;
            if (final.back() + 2 > '9') {
                final.back() = final.back() + 2 -10;
                increment = 1;
            } else {
                final.back() = final.back() + 2;
                increment = 0;
            }
            for (int i=final.length()-2;i>=0;i--) {
                if (final[i] + 1 + increment > '9') {
                    final[i] = final[i] + 1  + increment - 10; 
                    increment = 1;
                } else {
                    final[i] = final[i] + 1 + increment;
                    increment = 0;
                }

            }
        }
        cout << final << endl;

        

    }

    return 0;
}
