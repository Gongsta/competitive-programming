#include <bits/stdc++.h>

using namespace std;

/* So my initial solution was right. Actually the fix was just storing into the
array at the beginning. And then when there is that edge case at the end,
just recheck the entire array... 
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        int temp[n];
        bool issorted[n];
        bool works = true;
        vector<pair<int,int>> v;
        int prev_l = 0;
        int prev_r = 0;
        for (int j=0;j<n;j++) {
            for (int i=0;i<m;i++) {
                cin >> arr[j][i];
            }
        }
        for (int j=0;j<n;j++) {
            int count = 0;
            int l = 0;
            int r = 0;
            for (int i=1;i<m;i++) {
                if (arr[j][i] < arr[j][i-1]) {
                    count++;
                    if (count == 1) {
                        l = i - 1;
                    } else if (count == 2) {
                        r = i;
                    } else {
                        works = false;
                        break;
                    }
                }
            }
            if (count != 0) { // Insert the two positions
                int temp[m];
                for (int i=0;i<m;i++) {
                    temp[i] = arr[j][i];
                }

                sort(temp, temp+m);
                int new_count = 0;
                l = 0;
                r = 0;
                for (int i=0;i<m;i++) {
                    if (temp[i] != arr[j][i]) {
                        new_count++;
                        if (new_count == 1) {
                            l = i;
                        } else if (new_count == 2) {
                            r = i;
                        } else {
                            works = false;
                        }
                    }
                }
                v.push_back({l, r});
                issorted[j] = false;
            } else {
                issorted[j] = true;
            }
        }
        if (v.size() != 0) {
            prev_l = v.back().first;
            prev_r = v.back().second;
            v.pop_back();
            for (auto x: v) {
                if (x.first != prev_l || x.second != prev_r) {
                    works = false;
                    break;
                }
            }
            
            for (int j=0;j<n;j++) {
                if (!issorted[j]) continue; // We already checked for those not sorted
                if (arr[j][prev_l] != arr[j][prev_r]) {
                    works = false;
                    break;
                }

            }
        }

        if (works) {
            cout << prev_l + 1 << " " << prev_r + 1 << endl;

        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}