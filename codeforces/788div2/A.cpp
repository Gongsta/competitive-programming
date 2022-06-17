#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int neg_count = 0;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            if (arr[i] < 0 ) {
                neg_count++;
            }
        }
        bool works = true;
        for (int i=0;i<n;i++) {
            if (i < neg_count && arr[i] > 0) {
                arr[i] = -arr[i];
            } else if (i >= neg_count && arr[i] < 0) {
                arr[i] = -arr[i];
            }
            if (i > 0) {
                if (arr[i] < arr[i-1]) {
                    works = false;
                    break;
                }
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
