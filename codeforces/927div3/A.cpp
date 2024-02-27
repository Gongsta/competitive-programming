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
        string s;
        cin >> s;
        int count = 0;
        for (int i=0;i<n;i++) {
            if (s[i] == '@') count++;
            if (s[i] == '*') {
                if (i != n-1 && s[i+1] == '*') break;
            }
        }
        cout << count << endl;
    }

    return 0;
}
