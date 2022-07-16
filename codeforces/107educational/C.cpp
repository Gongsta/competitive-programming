#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    while (q--) {
        int t;
        cin >> t;
        int pos;
        for (int i=0;i<n;i++) {
            if (a[i] == t) {
                pos = i;
                cout << pos + 1;
                if (q == 0) {
                    cout << endl;
                } else {
                    cout << " ";
                }
                break;
            }
        }
        for (int i=pos;i>0;i--) {
            a[i] = a[i-1];
        }
        a[0] = t;
    }
        
    return 0;
}
