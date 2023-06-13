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
        if (n % 2 == 0) { // count down
            for (int i=1;i<=n;i++) {
                for (int j=0;j<m;j++) {
                    cout << i + n*j;
                    if (j != m-1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        } else if (m % 2 == 0) { // count horizontally
            for (int i=0;i<n;i++) {
                for (int j=1;j<=m;j++) {
                    cout << i * m + j;
                    if (j != m) {
                        cout << " ";
                    }
                }
                cout << endl;
            }

        } else {
            for (int i=1;i<=n;i++) {
                for (int j=0;j<m;j++) {
                    if (j%2 == 0) {
                        cout << i + n*j;
                    } else {
                        if (i != n) {
                            cout << i + n*j + 1;
                        } else {
                            cout << i *j + 1;
                        }
                    }
                    if (j != m-1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }


        }
        

    }

    return 0;
}
