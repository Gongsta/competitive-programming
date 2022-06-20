#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
4 -4 4 -4
8 0 8 0 (+4)
0 -8 0 0 (+8)
-8 -8 0 0 (+8)
-8 -8 -8 -8 (+8)
0 0 0 0 (+8)

1 -2 3 -4 5

*/

int a[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        

    }

    return 0;
}
