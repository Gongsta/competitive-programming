#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n >> q;
        int a[n+1];
        int max_num = 0;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            max_num = max(max_num, a[i]);
        }
        int max_idx = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] == max_num ) {
                max_idx = i;
                break;
            }
        }
        int total[n+1];
        memset(total, 0, sizeof(total));
        int j = 2;
        int i = 1;
        while (i<max_idx) {
            if (a[i] > a[j]) {
                total[i] += 1;
                j++;
            } else {
                total[j] += 1;
                i = j;
                j = i+1;
            }
        }

        while (q--) {
            int i,k;
            cin >> i >> k;
            if (i < max_idx) {
                if (i == 1) {
                    cout << min(total[i], k) << endl;
                } else {
                    if (i - k -2 >= 0) {
                        cout << 0 << endl;
                    } else {
                        cout << min(total[i], k-i+2) << endl;
                    }

                }
            } else if (i == max_idx) {
                if (i == 1) {
                    if (k - max_idx + 1 < 0) {
                        cout << 0 << endl;
                    } else {
                        cout << k - max_idx + 1 << endl;
                    }

                } else {
                    if (k - max_idx + 2 < 0) {
                        cout << 0 << endl;
                    } else {
                        cout << k - max_idx + 2 << endl;
                    }

                }

            } else if (i > max_idx) {
                cout << 0 << endl;
            }
        }


    }

    return 0;
}
