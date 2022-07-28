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
        int x = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            x ^= a[i];
        }
        if (x == 0) {
            cout << "YES" << endl;
        } else {
            int temp = 0;
            int temp2;
            bool has_zero = false;
            bool has_x = false;
            bool works = false;
            for (int i=0;i<n-1;i++) {
                temp ^= a[i];
                if (temp == 0) {
                    temp2 = a[i+1];
                    for (int j=i+2;j<n;j++) {
                        temp2 ^= a[j];
                    }
                    if (temp2 == x) {
                        if (has_x) {
                            has_zero = true;
                            break;
                        }
                    }
                } else if (temp == x) {
                    temp2 = a[i+1];
                    for (int j=i+2;j<n;j++) {
                        temp2 ^= a[j];
                    }
                    if (temp2 == 0) {
                        has_x = true;
                    }
                } else {
                    continue;
                }
            }
            if (has_x && has_zero) {
                works = true;
            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }
    }

    return 0;
}
