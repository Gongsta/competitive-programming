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
        int start, end = -1;
        for (int i=0;i<n;i++) {
            if (s[i] == '*') {
                if (start == -1) {
                    start = i;
                } else {
                    end = i;
                }
                count++;
            }
        }
        ll ans = 0;
        int l = 0;
        if (start == -1 || end == -1) {
            cout << 0 << endl;

        } else {
            for (int i=start;i<=end;i++) {
                if (s[i] == '*') {
                    l++;
                } else {
                    ans += min(l,count-l);
                }
            }
            cout << ans << endl;
        

        }

    }

    return 0;
}
