#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int n,m;
int dist(int x, int y) {
    return n - x + m - y;
}

int grid[1000][1000];
bool dp[1000][1000];
bool solved[1000][1000];

bool solve(int x, int y, int target) {
    if (solved[x][y]) return dp[x][y];
    if (abs(target - grid[x][y]) > dist(x,y)) {
        return false;
    }
    if (x == 0 && y == 0) {
        // solved[x][y] = true;
        dp[x][y] = (grid[x][y] == target);
    } else if (x == 0) {
        dp[x][y] = solve(x,y-1, target - grid[x][y]);
    } else if (y == 0) {
        dp[x][y] = solve(x-1,y, target - grid[x][y]);
    } else {
        dp[x][y] = solve(x-1, y, target - grid[x][y]) || solve(x,y-1, target - grid[x][y]);
    }
    solved[x][y] = true;
    return dp[x][y];

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> grid[i][j];
                dp[i][j] = 0;
                solved[i][j] = false;
            }
        }
        bool works = solve(n-1,m-1,0);
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
