#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        int arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n, greater<int>());
        long long int min_chairs = 0;
        for (int i=0;i<n;i++) {
            min_chairs += arr[i] + 1;
        }
        min_chairs += arr[0] - arr[n-1];
        if (min_chairs <= m) {
            cout << "YES" << endl;

        } else {
            cout << "NO" << endl;
        }
        

    }

    return 0;
}
