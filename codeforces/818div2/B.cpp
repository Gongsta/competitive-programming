#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k,c,r;
        cin >> n >> k >> r >> c;
        r--;
        c--;
        string ss;
        for (int i=0;i<n;i++) {
            ss += '.';
        }
        string s[n];
        for (int i=0;i<n;i++) {
            s[i] = ss;
        }
        s[r][c] = 'X';


    }

    return 0;
}
