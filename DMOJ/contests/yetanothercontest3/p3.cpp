#include <bits/stdc++.h>

using namespace std;

bitset<100000> increasing; // Relative to the previous elemnet
bitset<100000> decreasing;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    int t,l,r;
    
    int longest_increasing = 0;
    int longest_decreasing = 0;
    int temp_inc = 0;
    int temp_dec = 0;
    while (M--) {
        cin >> t >> l >> r;
        for (int i=l+1;i<=r; i++) {
            if (t == 1) {
                temp_dec = 0;
                if (decreasing[i]) {
                    cout << -1;
                    return 0;
                }
                increasing[i] = 1;
                temp_inc++;
                longest_increasing = max(longest_increasing, temp_inc);

            } else if (t == 2) {
                temp_inc = 0;
                if (increasing[i]) {
                    cout << -1;
                    return 0;
                }
                temp_dec += 1;
                longest_decreasing = max(longest_decreasing, temp_dec);
                decreasing[i] = 1;
            }
        }
    }
    
    int max_num =max(longest_decreasing, longest_increasing);
    

    return 0;
}
