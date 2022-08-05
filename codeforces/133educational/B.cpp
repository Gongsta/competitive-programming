#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int a[k];
        for (int i=0;i<k;i++) {
            a[i] = i;
        }
        int j = 0;
        cout << k << endl;
        for (int l=0;l<k;l++) {
            cout << a[l] + 1;
            if (l == k-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
        for (int i=0;i<k-1;i++) {
            swap(a[j], a[k-1]);
            for (int l=0;l<k;l++) {
                cout << a[l] + 1;
                if (l == k-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
            j++;

        }

    }

    return 0;
}
