#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,x;
        cin >> n >> x;
        ll arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for (int i=1;i<n;i++) {
            arr[i] += arr[i-1];
        }
        ll total = 0;
        for (int i=0;i<n;i++) {
            if (x - arr[i] >= 0) {
                total += x - arr[i] + 1;
            } else {
                break;
            }
        }
        cout << total << endl;

    }

    return 0;
}
