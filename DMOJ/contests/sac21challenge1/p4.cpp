#include <bits/stdc++.h>

using namespace std;

int arr[1000001] = {0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Sum until i
    
    int N, Q;
    

    cin >> N >> Q;
    for (int i=1;i<=N; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int l, r;
    while (Q--) {
        cin >> l >> r;
        cout << (arr[r] - arr[l-1]) / (r-l+1) << endl;
    }
    return 0;
}
