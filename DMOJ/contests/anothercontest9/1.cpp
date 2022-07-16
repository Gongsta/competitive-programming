#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a+4);
        set<pair<int, int>> s;
        do {
            s.insert({a[0] + a[1], a[2] + a[3]});
        } while (next_permutation(a, a+4));
        cout << s.size() << endl;
        for (auto x : s) {
            cout << x.first << " " << x.second << endl;
        }
    }

    return 0;
}
