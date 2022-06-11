#include <bits/stdc++.h>

using namespace std;


int arr[200000];
int sum_arr(int a, int b)  {
    if (a == 0) {
        return arr[b];
    } else {
        return arr[b] - arr[a-1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string pattern;
    int n,k;
    while (t--) {
        cin >> n >> k;
        cin >> pattern;
        int B_i = 0;
        
        arr[0] = (pattern[0] == 'B') ? 1 : 0;
        for (int i=1; i<n;i++) {
            if (pattern[i] == 'B') {
                arr[i] = arr[i-1] + 1;
            } else {
                arr[i] = arr[i-1];
            }
        }
        
        int min_k = k;
        for (int i=k-1;i<n;i++) {
            if (k - (sum_arr(i-k+1, i)) < min_k) {
                min_k = k - sum_arr(i-k, i);
            }
            if (min_k == 0) {
                break;
            }
        }
        
        cout << min_k << endl;

    }
    return 0;
}