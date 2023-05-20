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
        string arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        bool works[n];
        memset(works, 1, sizeof(works));
        for (int j=0;j<k;j++) {
            for (int i=0;i<n;i++) {
                if (arr[i][j] != arr[0][j]) {
                    works[i] = false;
                }
            }
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (works[i]) {
                ans++;
            }
        }
        cout << ans << endl;



    }

    return 0;
}
