#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        ll upper = n * ceil((double)k/(double)(n-1));
        if (k % (n - 1) == 0) {
            cout << upper - 1 << endl;

        } else {
            cout << upper - n + ((k) % (n - 1))<< endl;
        }

    }

    return 0;
}
