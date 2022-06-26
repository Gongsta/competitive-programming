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

        int sum = 0;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            if (arr[i] > 1) {
                sum += arr[i] - 1;
            }
        }
        if (sum % 2 == 0) {
            cout << "maomao90" << endl;
        } else {
            cout << "errorgorn" << endl;
        }

    }

    return 0;
}
