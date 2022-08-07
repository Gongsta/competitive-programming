#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// This is so simple, yet so clever!
pair<int,int> reduce(int d, int k) {
    return make_pair(d/gcd(d,k), k/gcd(d,k));
}
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
        int d = 0;
        int k = 0;
        map<pair<int, int>, int> m;
        for (int i=0;i<n;i++) {
            if (s[i] == 'K') {
                k++;
            } else {
                d++;
            }
            cout << ++m[reduce(d,k)];
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
        

    }

    return 0;
}
