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
        string s;
        cin >> n >> s;
        int end = 0;
        for (int i=1;i<n;i++) {
            if (s[i] < s[i-1] || (i != 1 && (s[i] <= s[i-1]))) {
                end = i;
            } else {
                break;
            }
        }
        for (int i=0;i<=end;i++) {
            cout << s[i];
        }
        for (int i=end;i>=0;i--) {
            cout << s[i];
        }
        cout << endl;

        }



    return 0;
}
