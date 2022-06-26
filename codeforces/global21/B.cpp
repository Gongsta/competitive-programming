#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        bool has_zero = true;
        for (int i=0;i<n;i++) {
            if (a[i] != 0) {
                has_zero = false;
            }
        }
        if (has_zero) {
            cout << 0 << endl;
        } else {
            vector<int> pos;
            for (int i=0;i<n;i++) {
                if (a[i] != 0) {
                    if (i==0 || (i>0 && a[i-1] == 0)) {
                        pos.push_back(i);
                    } 
                }
            }
            if (pos.size() <= 1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }

    }

    return 0;
}
