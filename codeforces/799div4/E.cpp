#include <bits/stdc++.h>

using namespace std;

// This doesn't work, see the binary string problem

int curr_sum = 0;
bool can(vector<int>& pos, int m) {
    int k = pos.size();
    int x = k - m;
    for (int i=0;i<m+1;i++) {
        if ((i+x-1) - i == curr_sum) {
            return true;
        }
    }
    return false;
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int arr[n];
        vector<int> pos;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            if (arr[i] == 1) {
                pos.push_back(i);
                curr_sum++;
            }
        }
        if (curr_sum < s) {
            cout << -1 << endl;
        } else {
            int l = 0;
            int r = n - 1;
            int count = 0;
            while (l<=r) {
                int mid = (l + r) / 2;
                if (can(pos, mid)) {
                    r= mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            cout << curr_sum - (r-l) << endl;
            }
        }
        
    return 0;
}
