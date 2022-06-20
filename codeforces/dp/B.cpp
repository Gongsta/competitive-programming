#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> letters;
    char x;
    while (k--) {
        cin >> x;
        letters.insert(x);
    }
    ll total = 0;
    ll count = 0;
    for (int i=0;i<n;i++) {
        if (!letters.count(s[i])) {
            total += count * (count + 1 ) / 2;
            count =0;

        } else {
            count++;
            if (i == n-1) {
                total += count * (count + 1 ) / 2;
            }
        }
    }
    cout << total << endl;

    return 0;
}
