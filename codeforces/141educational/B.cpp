#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// Made the mistake of inverting my rows

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int a[n][n];
        int i = 0;
        int j = 0;
        int top = n*n;
        int bottom = 1;

        while (j < n) {
            if ((i + j) % 2 == 0) {
            a[j][i] = top;
            top -= 1;
            } else {
                a[j][i] = bottom;
                bottom += 1;
            }
            if (j % 2 == 1) {
                i--;
            } else {
                i++;
            }
            if (i == n) {
                j++;
                i--;
            } else if (i == -1) {
                i++;
                j++;

            }
        }
        
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout << a[i][j];
                if (j != n-1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
        

    return 0;
}
