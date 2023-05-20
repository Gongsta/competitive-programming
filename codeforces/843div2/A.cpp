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
        
        int first_b = -1;
        int last_b = -1;
        for (int i=0;i<s.length();i++) {
            if (s[i] == 'b') {
                last_b = i;
                if (first_b == -1) {
                    first_b = i;
                }
            }
        }
        if (first_b == -1) {
            cout << "a "<< s.substr(1, s.length() - 1) << " a" << endl;
        } else if (first_b == 0) {

        }  else if (last_b == s.length() - 1) {

        }
        else  {
            cout << s.substr(0, first_b) << " " << s.substr(first_b, last_b - first_b + 1) << " " <<  s.substr(last_b + 1, s.length() - last_b - 1) << endl;

        }


        

    }

    return 0;
}
