#include <bits/stdc++.h>

using namespace std;

// I feel kind of stupid for not being able to initially do this
// 2 1 3 
// 1 2 3 (you never have a choice for 2, the odd)
// 2 3 1
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        for (int i=n-1;i>0;i-=2) {
            if (arr[i] < arr[i-1]) {
                swap(arr[i], arr[i-1]);
            }
        }
        bool works = true;
        for (int i=1;i<n;i++) {
            if (arr[i] < arr[i-1]) {
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
