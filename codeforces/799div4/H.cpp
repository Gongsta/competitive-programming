#include <bits/stdc++.h>

using namespace std;

int arr[200000];

map<int,vector<int>> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        m.clear();
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            m[arr[i]];
        }
        int curr_sum = 0, best = 0;
        int best_l = 0, best_r = 0, best_a = 0;
        for (auto& x: m) {
            curr_sum = 0;
            int l = 0, r = 0;
            int xx;
            for (int i=0;i<n;i++) {
                if (arr[i] != x.first) {
                    xx = -1;
                } else {
                    xx = 1;
                }
                if (xx > curr_sum+xx) {
                    l = i;
                    r = i;
                    curr_sum = xx;

                } else {
                    r = i;
                    curr_sum = curr_sum + xx;
                }
                if (curr_sum > best) {
                    best_l = l;
                    best_r = r;
                    best = curr_sum; 
                    best_a = arr[i];
                }
            }
        }
        cout << best_a << " " <<  best_l + 1 << " " << best_r + 1<< endl;
        

    }

    return 0;
}
