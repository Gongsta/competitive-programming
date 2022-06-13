#include <bits/stdc++.h>

using namespace std;

int arr[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long int total = 0;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            total += arr[i] / k;
            arr[i] = arr[i] % k;
        }
        sort(arr, arr+n);
        
        for (int i=0,j=n-1;i<j;i++,j--) {
            while (arr[i] + arr[j] < k && i < j) i++;
            if (i == j) break;
            total++;
        }
        
        cout << total << endl;
    }

    return 0;
}
