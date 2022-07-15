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
        if (n < 2) {
            if (a[0] == 1) {
                cout << "2 1" << endl;
            } else {
                cout << "1 2" << endl;
            }

        } else {
            
            if (a[0] == 1) {
                cout << n+1 << " ";
                for (int i=0;i<n;i++) {
                    cout << i + 1;
                    if (i == n-1) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                }
            } else if (a[n-1] == 0) {
                for (int i=0;i<n;i++) {
                    cout << i + 1 << " ";
                }
                cout << n+1 << endl;


            } else {
                bool works = false;
                int jump = -1;
                for (int i=0;i<n-1;i++) {
                    if (a[i] == 0 && a[i+1] == 1) {
                        works = true;
                        jump = i;
                        break;
                    }
                }
                if (works) {
                    for (int i=0;i<=jump;i++) {
                        cout << i + 1 << " ";
                    }
                    cout << n+1 << " ";
                    for (int i=jump+1;i<n;i++) {
                        cout << i + 1;
                        if (i == n-1) {
                            cout << endl;
                        } else {
                            cout << " ";
                        }

                    }

                } else {
                    cout << -1 << endl;
                }

            }
        }
        

    }

    return 0;
}
