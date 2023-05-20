#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> s;
        int p;
        int order = n-1;
        int ans[n];
        memset(ans, -1, sizeof(ans));
        for (int i=0;i<m;i++) {
            cin >> p;
            if (s.count(p)) continue;
            s.insert(p);
            ans[order] = i+1;
            order--;
        }
        for (int i=0;i<n;i++) {
            cout << ans[i];
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }

        }
        


    }

    return 0;
}
