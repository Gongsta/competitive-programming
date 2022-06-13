#include <bits/stdc++.h>

using namespace std;

int arr[200][200];
int sum_diag(int x, int y, int n, int m) {
    int total = arr[x][y];
    int counter = 1;
    for (int i=x+1;i<n;i++) {
        if (y+counter < m) {
            total += arr[i][y+counter];
        }
        if (y-counter >= 0) {
            total += arr[i][y-counter];
        }
        
        counter++;
    }
    counter = 1;
    for (int i=x-1;i>=0;i--) {
        if (y+counter < m) {
            total += arr[i][y+counter];
        }
        if (y-counter >= 0) {
            total += arr[i][y-counter];
        }
        counter ++;
    }
    return total;
}
int main()
{
    int t;
    cin >> t;
    int m, n;
    while (t--) {
        cin >> n >> m;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> arr[i][j];
            }
        }
        
        int total = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                total = max(total, sum_diag(i,j,n,m));
            }
        }
        cout << total << endl;
        
    }

    return 0;
}
