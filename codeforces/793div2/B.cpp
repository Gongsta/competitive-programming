#include <bits/stdc++.h>

using namespace std;

int arr[200000];
int sorted[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            sorted[i] = arr[i];
        }
        sort(sorted, sorted+n);
        int min_val = 0;
        bool min_bound_bool = false;
        int min_bound;
        for (int i=0;i<n;i++) {
            if (arr[i] != sorted[i]) {
                if (!min_bound_bool){
                    min_bound_bool = true;
                    min_bound = sorted[i];
                } else {
                    min_bound = min_bound&sorted[i];
                }
            }
        }
        cout << min_bound << endl;

    }

    return 0;
}
