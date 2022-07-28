#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


string s,t;

void solve(int i, int j, int len_s, int len_t) {
    if (s[i] == s[j]) {
        solve(i+1, j+1, len_s+1, len_t+1);

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        cin >> s >> t;


    }

    return 0;
}
