#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        m.clear();
        int x;
        for (int i=0;i<n;i++) {
            cin >> x;
            if (m.count(x)) {
                m[x]++;
            } else {
                m[x] = 1;
            }
        }
        vector<int> v;
        for (auto x: m) {
            if (x.second >= 3) {
                v.push_back(x.first);
                break;
            }
        }
        if (v.size() == 0) {
            cout << -1 << endl;
        } else {
            cout << v[0] << endl;
        }


    }

    return 0;
}
