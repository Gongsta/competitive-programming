#include <bits/stdc++.h>

using namespace std;

int arr[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            arr[i] = arr[i] % 10;
        }
        sort(arr, arr+n);
        bool found = false;
        for (int i=0;i<n;i++) {
            if (i!=0 && arr[i] == arr[i-1]) continue;
            int target; 
            if (arr[i] <= 3) {
                target = 3 - arr[i];
            } else {
                target = 13 - arr[i];
            }
            for (int j=i+1;j<n;j++) {
                if (arr[j] == arr[j-1] && j!= i+1) continue;
                // Binary search
                int new_target;
                if (target - arr[j] < 0) {
                    new_target = target + 10 -arr[j];
                } else {
                    new_target = target-arr[j];
                }
                if (binary_search(arr+j+1, arr+n,new_target)) {
                    found = true;
                    break;
                } else {
                }
            }
            if (found) {
                break;
            }
        }
        
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
