#include <bits/stdc++.h>

using namespace std;

// This doesn't work, see the binary string problem, but that solution doesn't work
// for this problem because they optimize for different things

int arr[200000];
int sum_prefix(int a, int b) {
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
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> pos;
        int curr_sum = 0;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        for (int i=1;i<n;i++) {
            arr[i] += arr[i-1];
        }
        int max_len = -1;
        for (int i=0;i<n;i++) {
            int l = i;
            int r = n-1;
            while (l<=r) {
                int mid = (l+r)/2;
                if (sum_prefix(i, mid) <= s)  {
                    if (sum_prefix(i, mid)== s) {
                        max_len = max(max_len, mid-i + 1);
                    }
                    l = mid + 1;
                } else if (sum_prefix(i, mid) > s) {
                    r = mid - 1;
                }
            }
        }
        if (max_len != -1) {
            cout << n - max_len << endl;
        } else {
            cout << max_len << endl;
        }
        }
        
    return 0;
}
