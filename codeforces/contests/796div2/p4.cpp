#include <bits/stdc++.h>

using namespace std;

int arr[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long int T, n, k;
    /*
    1. If k<=n; then return (largest contiguous sum of length k+ (k)(k-1)/2, i.e. sum(1, k - 1))
    2. If k > n; then (sum a1 + a2 + ... + an + (k)(k-1)/2 + (k-n)(k-n+1)/2 )
    2. double check that its n-k and
    2. NEW Find the smallest consecutive sum, do that for 
    */
   cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        long long int total = 0;
        if (k > n) {
            for (int i=1;i<=n;i++) {
                total += arr[i];
            }
            total += (n)*(n-1)/2; // total after n minutes
            
            // Strategy: Stay in the same place
            long long int same_place = k -2*n + 1;
            total += same_place * 1;
            total += same_place * (k-same_place - n);
            total += (k-same_place-n)*(k-same_place - n+1);
        } else {
            total += (k)*(k-1)/2;
            long long int largest_sum = 0;
            long long int curr_sum = 0;
            for (int j=1;j<1+k;j++) {
                curr_sum += arr[j];
            }
            largest_sum = max(largest_sum, curr_sum);
            for (int i=1; i<=n-k;i++) {
                curr_sum -= arr[i];
                curr_sum += arr[i+k];
                largest_sum = max(largest_sum, curr_sum);
        }
            total += largest_sum;
        }

        cout << total << endl;
    }

    return 0;
}
