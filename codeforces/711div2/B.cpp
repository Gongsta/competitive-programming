#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

map<int, int> m;

bool check_empty() {
    for (auto x: m) {
        if (x.second != 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,W;
        cin >> n >> W;
        for (int i=0;i<n;i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        int ans = 0;
        while (!check_empty()) {
            int W_temp = W;
            for (int i=30;i>=0;i--) {
                while (m[1<<i] > 0 && W_temp >= (1<<i)) {
                    m[1<<i]--;
                    W_temp -= 1<<i;
                }
            }
            ans++;
        }
        cout << ans << endl;
    }


    return 0;
}
