#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,k;
    cin >> n >> m >> k;
    int x[m+1];
    for (int i=0;i<=m;i++) {
        cin >> x[i];
    }
    int final = 0;
    for (int i=0;i<m;i++) {
        int count = 0;
        for (int j=0;j<n;j++) {
            if ((((1 << j) & x[i]) >> j) ^(((1 << j) &x[m]) >> j)) {
                count++;
            }
        }
        if (count <= k) {
            final++;
        }
    }
    cout << final << endl;
    

    return 0;
}
