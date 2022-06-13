#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int length = 0;
        bool hasB = false;
        bool hasR = false;
        bool works = true;
        bool begin = true;
        for (int i=0;i<n;i++) {
            if (s[i] == 'W' && !begin) {
                if (length < 2) {
                    works = false;
                    break;
                }
                if (!hasB || !hasR) {
                    works = false;
                    break;
                }
                length = 0;
                hasB = false;
                hasR = false;
                begin = true;
            } else if (s[i] == 'B') {
                begin = false;
                hasB = true;
                length++;
            } else if (s[i] == 'R'){
                begin = false;
                hasR = true;
                length++;
            }
            if (i == n-1 && !begin) {
                if (length < 2) {
                    works = false;
                    break;
                }
                if (!hasB || !hasR) {
                    works = false;
                    break;
                }
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
