#include <bits/stdc++.h>

using namespace std;

// I am absolutely pathetic, it was because my sum_arr function was not returning a long long int
long long int arr[200000];
long long int sum_arr(int a, int b) {
    if (a == 0) {
        return arr[b];
    } else {
        return (arr[b] - arr[a-1]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i=1;i<n;i++) {
        arr[i] = arr[i] + arr[i-1];
    }
    int x,y;
    while (q--) {
        cin >> x >> y;
        long long int total = sum_arr(n-x,n-x+y-1);

        cout << total << endl;
        
    }


    return 0;
}
