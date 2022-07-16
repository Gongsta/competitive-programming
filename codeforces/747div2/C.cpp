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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        bool works = true;
        int largest = -1;
        for (int i=0;i<s.length();i++) {
            if (s[i] != c) {
                largest = i;
            }
        }
        if (largest == -1) {
            cout << 0 << endl;
        } else {
            for (int i=0;i<s.length();i++) {
                if (s[i] == c) {
                    largest = i;
                }
            }
            bool works = true;
            for (int i=0;i<s.length();i++) {
                if (s[i] != c && (i + 1) % (largest + 1) == 0) {
                    works = false;
                    break;
                }
            }
            if (works) {
                cout << 1 << endl;
                cout << largest + 1 << endl;
            } else {
                cout << 2 << endl;
                cout << n << " " << n-1 << endl;
            }
            
        }
        

    }

    return 0;
}
