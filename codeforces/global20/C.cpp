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
        int arr[n];
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        int count = 0;
        for (int i=1;i<n;i++) {
            if (arr[i] == arr[i-1]) {
                count++;
            }
        }
        if (count > 0) {
            count--;
        }
        cout << count << endl;

    }

    return 0;
}
