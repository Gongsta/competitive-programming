#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,left,right;
        cin >> n >> left >> right;
        ll a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a, a+n);

        ll total = 0;
        for (int i=0;i<n-1;i++) {
            int l = i+1;
            int r = n-1;
            // Binary search max_l
            int max_l = -1;
            int min_l = -1;
            while (l <= r) {
                int mid = (l+r)/2;
                if (a[i] + a[mid] > right) {
                    r = mid - 1;
                } else {
                    if (a[i] + a[mid] >= left) {
                        max_l = mid;
                    }
                    l = mid + 1;
                }
            }
            l = i+1;
            r = n-1;
            while (l <= r) {
                int mid = (l+r)/2;
                if (a[i] + a[mid] < left) {
                    l = mid + 1;
                } else {
                    if (a[i] + a[mid] <= right) {
                        min_l = mid;
                    }
                    r = mid - 1;
                }
            }
            if (max_l != -1) {
                total += (max_l - min_l + 1);
            }
            
        }
        cout << total << endl;



    }

    return 0;
}
