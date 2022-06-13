// Array sum + binary search
#include <bits/stdc++.h>

using namespace std;

int arr[150000];
int main()
{
    int t;
    cin >> t;
    int n,q;
    while (t--) {
        cin >> n >> q;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n, greater<int>());
        for (int i=1;i<n;i++) {
            arr[i] = arr[i-1] + arr[i];
        }
        int x;
        while (q--) {
            cin >> x;
            int l = 0;
            int r = n-1;
            int mid;
            int ans = -1;
            while (l<=r) {
                mid = (l+r)/2;
                if (arr[mid] >= x) {
                    r = mid - 1;
                    ans = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (ans == -1) {
                cout << -1 << endl;
            } else {
                cout <<ans + 1<< endl;
                
        }
        
        }
    }
    return 0;
}
