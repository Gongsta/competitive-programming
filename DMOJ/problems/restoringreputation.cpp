#include <bits/stdc++.h>

using namespace std;

/* This is similar to the shortest length problem to convert a word A into B.
but made a bit more complicated by adding the complexity of various costs
for doing different operations! Super interesting!
*/

string s1;
string s2;
int dp[1000][1000];
bool solved[1000][1000];
int D,I,R;
int min_cost;

int solve(int x, int y) {
    if (x<0) {
        return 0;
    }
    if (y<0) {
        return 0;
    }
    if (solved[x][y]) {
        return dp[x][y];
    }
    
    int cost = R;
    solved[x][y] = true;
    if (s1[x] == s2[y]) {
        cost = 0;
    }

    dp[x][y] = min(solve(x-1,y)+I, solve(x,y-1)+D);
    dp[x][y] = min(dp[x][y], solve(x-1,y-1)+cost);

    return dp[x][y];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> D >> I >> R;
    
    if (D + I < R) {
        R = D + I;
    }
    cin >> s1;
    cin >> s2;
    solve(s1.length()-1,s2.length()-1);
    
    cout << dp[s1.length()-1][s2.length()-1] << endl;

    return 0;
}
