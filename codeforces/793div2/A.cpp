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
        int count = 0;
        for (int i=0;i<n/2;i++) {
            if (s[i+1] == s[s.length()-1-i]) {
                count++;
            }
        }
        for (int i=n-1;i>=n/2;i--) {
            if (s[i-1] == s[i]) {
                count++;
            }
        }
        if (n % 2 == 1) {
            count++;
        }
        cout << count << endl;

    }

    return 0;
}
