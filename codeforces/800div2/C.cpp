#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long int total = 0;
        long long int arr[n];
        bool has_val = false;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            total += arr[i];
            if (arr[i] != 0) {
                has_val = true;
            }
        }
        bool works = true;
        if (total == 0 && arr[0] >= 0 && arr[n-1] <= 0) {
            if (arr[0] == 0 && n != 1) {
                works = false;
            } 
        }
        if (has_val) {
            for (int i=n-1; i>=0; i--) {
                if (arr[i] > 0) { // Check that first value is negative
                    works = false;
                    break;
                } else if (arr[i] < 0) {
                    break;
                }
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
