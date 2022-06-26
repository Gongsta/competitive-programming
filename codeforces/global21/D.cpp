#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int path_length = 0;
        int start;
        int start_i = 0;
        int curr_min_i = 0;
        int curr_max_i = 0;
        int curr_min;
        int curr_max;
        for (int i=0;i<n;i++) {
            if (i == 0) {
                start = a[i];
                curr_min = a[i];
                curr_max = a[i];
            } else {
                if (a[i] < curr_min) {
                    curr_min = a[i];
                    curr_min_i = i;
                    if (curr_max != start) {
                        path_length++;
                        start = curr_max;
                        start_i = curr_max_i;
                    }
                } else if (a[i] > curr_max) {
                    curr_max = a[i];
                    curr_max_i = i;
                    if (curr_min != start) {
                        path_length++;
                        start = curr_min;
                        start_i = curr_min_i;
                    }
                    // Same case for min?
                    if (curr_max == n && curr_min_i < curr_max_i) {
                        curr_min = curr_max;
                        curr_min_i = curr_max_i;
                        start_i = curr_min_i;
                        path_length++;
                    }
                }
            }
            cout << start << endl;
            if (i == n-1) {
                if (curr_min_i != start_i) {
                    path_length++;
                } 
                if (curr_max_i != start_i) {
                    path_length++;
                }
                if (n-1 != curr_max_i && n-1 != curr_min_i) {
                    path_length++;
                }
            }
        }
        cout << path_length << endl;
    }

    return 0;
}
