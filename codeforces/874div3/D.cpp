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
        int p[n];
        for (int i=0;i<n;i++) {
            cin >> p[i];
        }
        int max_i = 0;
        for (int i=0;i<n;i++) {
            if (p[i] == n) {
                max_i = i;
                break;
            }
        }
        // Answer output: from max_i to n-1, l to r, 0 to l-1
        // Special case: max_i == n-1
        if (n == 1) {
            cout << p[0] << endl;
        }
        else if (max_i == n - 1 && p[max_i - 1] < p[0])
        {
            // We use the max_i as a segment
            cout << p[max_i] << " ";
            for (int i=0;i<max_i;i++) {
                cout << p[i];
                if (i == max_i - 1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        } 
        else {
            bool special_case = false;
            if (max_i == 0) { // EDGE CASE
                // We need to find the second largest number;
                for (int i = 0; i<n; i++)
                {
                    if (p[i] == n - 1)
                    {
                        max_i = i;
                        if (max_i == n-1) {
                            special_case = true;
                        }
                        break;
                    }
                }
            }
            if (special_case) {
                cout << p[n-1] << " ";
                for (int i=0;i<n-1;i++) {
                    cout << p[i];
                    if (i == n-2) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }

                }

            } else {
                for (int i=max_i;i<n;i++) {
                    cout << p[i] << " ";
                }
                int l = -1;
                if (max_i - 1 == 0) {
                    cout << p[max_i-1] << endl; 

                } else {
                    cout << p[max_i-1] << " ";
                }
                for (int i=max_i-2;i>=0;i--) {
                    if (p[i] < p[0]) {
                        l = i;
                        break;
                    } else {
                        cout << p[i];
                        if (i == 0) {
                            cout << endl;
                        } else {
                            cout << " ";
                        }
                    }
                }
                for (int i=0;i<=l;i++) {
                    cout << p[i];
                    if (i == l) {
                        cout << endl;
                    } else {
                        cout  << " ";
                    }
                }
            }
        }

    }

    return 0;
}
