#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m[251];
int calculate(int target_sum, int arr_len, int max_num) {
    if (target_sum <= 0) {
        return 0;
    }
    if (arr_len == 1) {
        if (max_num == target_sum) {
            // cout << "max_num / target" << target_sum;
            return 1;
        } else {
            return 0;
        }
    }
    int possibilities = 0;
    for (int i=1;i<=max_num; i++) {
        // cout << "target: " << target_sum - max_num << " arr_len:" << arr_len - 1 << " i:" << i << endl;
        possibilities += calculate(target_sum-max_num, arr_len - 1, i);
    }
    return possibilities;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    
    int possibilities = 0;
    for (int i=n/k; i<=n-k+1;i++) {
        possibilities += calculate(n,k,i);
        cout << possibilities << endl;
    }
    cout << possibilities << endl;
    return 0;
}
