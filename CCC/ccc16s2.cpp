#include <bits/stdc++.h>

using namespace std;

int a[101];
int b[101];
int arr[202];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // for max, just take the n highest values when you combine it, sum over these values
    // for min, sort a and sort b, and combine 
    int q,N;
    cin >> q >> N;
    //Maximum
    if (q == 2) {
        for (int i=0;i<2*N; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+2*N);
        long long int total = 0;
        for (int i=N;i<2*N;i++) {
            total += arr[i];
        }
        cout << total << endl;
    } else {
        for (int i=0;i<N; i++) {
            cin >> a[i];
        }

        for (int i=0;i<N; i++) {
            cin >> b[i];
        }
        sort(a, a+N);
        sort(b, b+N);
        long long int total = 0;
        for (int i=0;i<N; i++) {
            total += max(a[i], b[i]);
        }
        cout << total << endl;

    }

    

    return 0;
}
