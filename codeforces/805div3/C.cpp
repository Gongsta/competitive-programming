#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int u[n];
        map<int, int> smallest;
        map<int, int> largest;
        for (int i=0;i<n;i++) {
            cin >> u[i];
            if (!smallest.count(u[i])) {
                smallest[u[i]] = i;
            }
            largest[u[i]] = i;
        }
        while (k--) {
            int a,b;
            cin >> a >> b;
            if (!smallest.count(a) || !smallest.count(b)) {
                cout << "NO" << endl;
            } else {
                if (smallest[a] <= largest[b]) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
    
            }

        }

    }

    return 0;
}
