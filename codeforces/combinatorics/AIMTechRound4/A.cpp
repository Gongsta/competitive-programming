#include <bits/stdc++.h>

using namespace std;

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
    long long int total = 0;
    for (int i=0;i<n;i++) {
        long long int count = 0;
        for (int j=0;j<m;j++) {
            count += table[i][j];
        }
        long long int temp = 1;
        temp = temp << count;
        temp--;
        total += temp;
        temp = 1;
        temp = temp << (m-count);
        temp--;
        total += temp;
    }
    
    for (int i=0;i<m;i++) {
        long long int count = 0;
        for (int j=0;j<n;j++) {
            count += table[j][i];
        }
        long long int temp = 1;
        temp = temp << count;
        temp--;
        total += temp;
        temp = 1;
        temp = temp << (n-count);
        temp--;
        total += temp;
        total -= n;
    }
    
    cout << total << endl;

    return 0;
}