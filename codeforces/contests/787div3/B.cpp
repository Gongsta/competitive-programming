#include <bits/stdc++.h>

using namespace std;

int arr[31];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    int n;
    while (t--) {
        int total = 0;
        bool impossible = false;
        cin >> n;
        for (int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        for (int i=n;i>=2;i--) {
            while (arr[i] <= arr[i-1]) {
                if (arr[i] == 0) {
                    impossible = true;
                    break;
                }
                arr[i-1] /= 2;
                total++;
            }
        }
        if (impossible) {
            cout << "-1" << endl;
        } else {
            cout << total << endl;
        }

    }

    return 0;
}
