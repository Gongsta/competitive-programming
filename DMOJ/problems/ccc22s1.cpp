#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int count = 0;
    while (N>0) {
        if (N%4 == 0) {
            count++;
        }
        N-= 5;
    }
    if (N==0) {
        count++;
    }
    cout << count << endl;
    return 0;
}
