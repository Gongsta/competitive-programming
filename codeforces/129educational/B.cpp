#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        cin >> m;
        int b;
        int p = 0;
        for (int i=0;i<m;i++) {
            cin >> b;
            p += b;
            if (p >=n) {
                p-=n;
            }
        }
        cout << arr[p] << endl;
        
    }

    return 0;
}