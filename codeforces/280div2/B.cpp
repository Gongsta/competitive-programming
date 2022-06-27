#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double l;
    int n;
    cin >> n >> l; 
    double arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    double min_dist;
    if (n == 1) {
        min_dist = max(arr[0], l-arr[0]);
    } else {
        min_dist = arr[0];
    }

    for (int i=1;i<n;i++) {
        min_dist = max(min_dist, (arr[i]-arr[i-1])/2.0);
    }
    min_dist = max(min_dist, l-arr[n-1]);
        
    cout << setprecision(12) << fixed << min_dist << endl;

    return 0;
}
