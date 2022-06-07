#include <bits/stdc++.h>

using namespace std;

int arr[200001];
bitset<200001> modified;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long int n,q;
    cin >> n >> q;
    
    long long int t, x;
    
    long long int sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        sum += arr[i];
       modified[i] = 1;
    }

    long long int curr = 0;
    while (q--) {
        cin >> t;
        int i;
        if (t == 1) {
            cin >> i >> x;
            if (modified[i]) {
                sum -= arr[i];
                arr[i] = x;
                sum += arr[i];
            } else {
                sum -= curr;
                arr[i] = x;
                sum += arr[i];
                modified[i] = 1;
            }
        } else {
            cin >> x;
            sum = x * n;
            curr = x;
            modified.reset();
        }
        cout << sum << endl;
    }

    return 0;
}
