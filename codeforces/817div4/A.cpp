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
        map<char, int> m;
        for (auto x: s) {
            m[x]++;
        }
        if (n == 5 && m['T'] == 1 && m['i'] == 1 && m['m'] == 1 && m['u'] == 1 && m['r'] ==1) { 
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
