#include <bits/stdc++.h>

using namespace std;

int a[50001];
int b[50001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        bool T = true;
        int diff = 1 << 30;
        bool diff_uninit = true;
        int zero_diff = 0;

        for (int i=0;i<n;i++) {
            if (a[i] - b[i] < 0) {
                T = false;
                break;
            } 
            if (b[i] == 0) {
                zero_diff = max(zero_diff, a[i]);
                if (zero_diff > diff) {
                    T = false;
                    break;
                }
            } else {
                if (diff_uninit) {
                        diff_uninit = false;
                        diff = a[i] - b[i];
                    }
            
                if (a[i] - b[i] != diff) {
                    T = false;
                    break;
                }
            }
                
                
        }             
        if (zero_diff > diff) {
            T = false;
        }
        if (T) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
    return 0;
}
