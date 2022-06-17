#include <bits/stdc++.h>

using namespace std;

int factorial(int x) {
    if (x == 0) return 0; // I know that 0! = 1 but for this question
    if (x == 1) return 1;
    return x * factorial(x-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int table[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> table[i][j];
        }
    }
    int total = 0;
    for (int i=0;i<n;i++) {
        int count = 0;
        for (int j=0;j<m;j++) {
            count += table[i][j];
        }
        total += factorial(count);
        total += factorial(m-count);
    }
    
    for (int i=0;i<m;i++) {
        int count = 0;
        for (int j=0;j<n;j++) {
            count += table[j][i];
        }
        total += factorial(count);
        total += factorial(n-count);
        total -= n;
    }
    
    cout << total << endl;

    return 0;
}