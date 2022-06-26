#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n = 2*n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int total = 0;
    for (int i=1;i<n;i+=2) {
        total += arr[i] - arr[i-1];
    }
    cout << total << endl;
    

    return 0;
}
