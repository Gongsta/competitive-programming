#include <iostream>
#include <map>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        map<int, int> m;
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int min_n = n;
        int target_sum = 0;
        int curr_sum = 0;
        int curr_counter = 0;
        int curr_min_counter = n;
        for (int i=0;i<n;i++) {
            target_sum += a[i];
            curr_counter = 0;
            curr_min_counter = i+1;
            curr_sum = 0;
            for (int j=i+1;j<n;j++) {
                curr_sum += a[j];
                curr_counter++;
                if (curr_sum > target_sum) break;
                if (curr_sum == target_sum) {
                    curr_sum = 0;
                    curr_min_counter = max(curr_min_counter, curr_counter);
                    curr_counter = 0;
                }
                if (j == n-1 && curr_sum == 0) {
                    // cout << min_n << " " << i << endl;
                    min_n = min(min_n, curr_min_counter);
                }
            }
        }
        cout << min_n << endl;
        
        
    


    }

    return 0;
}
