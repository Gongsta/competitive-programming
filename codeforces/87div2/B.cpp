#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int eaten[n][m];
    memset(eaten, 0, sizeof(eaten));
    string grid[n];
    for (int i=0;i<n;i++) {
        cin >> grid[i];
    }
    int count = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j] == 'W') {
                if (i > 0 && grid[i-1][j] == 'P' && !eaten[i-1][j]) {
                    count++;
                    eaten[i-1][j] = 1;
                } else if (j > 0 && grid[i][j-1] == 'P' && !eaten[i][j-1]) {
                    count++;
                    eaten[i][j-1] = 1;
                } else if (i < n-1 && grid[i+1][j] == 'P' && !eaten[i+1][j]) {
                    count++;
                    eaten[i+1][j] = 1;
                } else if (j < m-1 && grid[i][j+1] == 'P' && !eaten[i][j+1]) {
                    count++;
                    eaten[i][j+1] = 1;
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}
