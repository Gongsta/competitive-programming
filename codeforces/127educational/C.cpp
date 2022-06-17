#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin >> n >> x;
        int arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int total = 0;
        for (int i=0;i<n;i++) {
            if (x - arr[i] >= 0) {
                total += x - arr[i] + 1;
            } else {
                break;
            }
        }

    }

    return 0;
}
