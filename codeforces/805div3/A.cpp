#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        string s = to_string(m);
        cout << m - (int) pow(10, s.length() - 1) << endl;

    }

    return 0;
}
