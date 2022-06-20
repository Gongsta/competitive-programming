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
        if (val[0] == '9') {
            if (val[final.length()-1] >= '2') {
                final += "1";
                for (int i=1;i<val.length()-1;i++) {
                    final += to_string(9 - (val[i]-'0'));
                }
                final += to_string(11 - (val[val.length()-1]-'0'));

            }

        } else {
            for (int i=0;i<val.length();i++) {
                final += to_string(9 - (val[i]-'0'));
            }
        }
        cout << final << endl;

        

    }

    return 0;
}
