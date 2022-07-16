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
        int grid[n+1][m+1];
        memset(grid,0, sizeof(grid));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (j == 1) {
                    if (i % 4 == 1 || i % 4 == 0) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                } else {
                    if (j % 4 == 2 || j % 4 == 0) {
                        grid[i][j] = !grid[i][j-1];
                    } else if (j% 4 == 1 || j % 4 == 3) {
                        grid[i][j] = grid[i][j-1];
                    } 

                }
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cout << grid[i][j];
                if (j == m) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }


    }

    return 0;
}
