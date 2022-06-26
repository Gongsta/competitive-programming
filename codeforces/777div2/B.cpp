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
        int grid[n][m];
        for (int i=0;i<n;i++) {
            string s;
            cin >> s;
            for (int j=0;j<m;j++) {
                grid[i][j] = s[j] - '0';
            }
        }

        bool works = true;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 0 && ((i>0 && j<m-1 && grid[i-1][j] && grid[i][j+1] && grid[i-1][j+1]) || (i<n-1 && j>0 && grid[i+1][j] && grid[i][j-1] && grid[i+1][j-1])
                                    || (i>0 && j>0 && grid[i-1][j] && grid[i][j-1] && grid[i-1][j-1]) || (i<n-1 && j<m-1 && grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1]))) {
                    works = false;
                    break;
                }
            }
            if (!works) {
                break;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
