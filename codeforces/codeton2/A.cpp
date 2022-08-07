#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        string a,b;
        cin >> a >> b;
        int a_i = n-1;
        int b_i = m -1;
        while (a_i > 0) {
            if (a[a_i] != b[b_i]) {
                break;
            }         
            if (a[a_i-1] != b[b_i-1]) {
                
            }
            
        }
        if (b_i != -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }

    return 0;
}
