#include <bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];
int c[100000];
int d[100000];

map<int, set<int>> m;
set<int> d_map;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        m.clear();
        d_map.clear();
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        for (int i=0;i<n;i++) {
            cin >> d[i];
        }
        int total = 1;
        for (int i=0;i<n;i++) {
            if (a[i] == b[i])  {
                m[a[i]].insert(b[i]);
                continue;
            }
            if (d[i] != 0) {
                d_map.insert(d[i]);
                continue;
            }
            if (m[a[i]].count(b[i]) || m[b[i]].count(a[i])) {
                total /= 2;
                continue;
            }
            if (d_map.count(a[i]) || d_map.count(b[i]) || m[a[i]].size() > 0 || m[b[i]].size() > 0) {
                m[a[i]].insert(b[i]);
                m[b[i]].insert(a[i]);
                continue;
            }
            m[a[i]].insert(b[i]);
            m[b[i]].insert(a[i]);
            total = (total * 2) % 1000000007;
        }
        cout << total << endl;


    }

    return 0;
}
