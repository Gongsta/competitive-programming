#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

/*
Strategy:
For odd number
Remove all for first, then the following ones you try to match. But it might not work

*/
int arr[50];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }

        if (n % 2 == 1) {
            cout << "Mike" << endl;
        } else {
            int min_val = 1<<30;
            int min_i = 0;
            for (int i=0;i<n;i++) {
                if (arr[i] < min_val) {
                    min_i = i;
                    min_val = arr[i];
                }
            }
            if (min_i % 2 == 0) {
                cout << "Joe" << endl;
            } else {
                cout << "Mike" << endl;
            }


        }

    }

    return 0;
}
