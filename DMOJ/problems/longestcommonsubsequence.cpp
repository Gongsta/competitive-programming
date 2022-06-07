#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[1001][1001];
bool solved[1001][1001];
int s1[1001];
int s2[1001];

int solve(int x, int y) {
    if (x >= N) {
        return 0;
    } 
    if (y >= M) {
        return 0;
    }
    if (solved[x][y]) {
        return dp[x][y];
    }
    if (s1[x] == s2[y]) {
        dp[x][y] = 1 + solve(x+1, y+1);
    } else {
        dp[x][y] = max(solve(x+1, y), solve(x,y+1));
    }
    solved[x][y] = true;
    return dp[x][y];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> s1[i];
    }
    for (int i=0;i<M;i++) {
        cin >> s2[i];
    }
    solve(0,0);
    cout << dp[0][0] << endl;
    return 0;
}