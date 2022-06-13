#include <bits/stdc++.h>

using namespace std;

int arr[51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        bool works = true;
        for (int i=3;i<=n;i++) {
            if (abs(arr[i] - arr[i-2]) % 2 != 0) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
