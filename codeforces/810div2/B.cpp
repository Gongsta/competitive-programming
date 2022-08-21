#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// I really struggled on this problem...

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,mm;
        cin >> n >> mm;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> pairs;
        map<int, int> m;
        int min_a = 1 << 30;
        for (int i=0;i<mm;i++) {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            m[x]++;
            m[y]++;
            pairs.push_back({x,y});
        }
        if (pairs.size() % 2 == 0) {
            cout << 0 << endl;
        } else {
            int min_a = 1 << 30;
            for (auto p: pairs) {
                int x = p.first;
                int y = p.second;
                if (m[x] % 2 == 1) {
                    min_a = min(min_a, a[x]);
                }
                if (m[y] % 2 == 1) {
                    min_a = min(min_a, a[y]);
                }
            }
            if (min_a == 1 << 30) {

            }
            cout << min_a << endl;

        }
        

    }

    return 0;
}
