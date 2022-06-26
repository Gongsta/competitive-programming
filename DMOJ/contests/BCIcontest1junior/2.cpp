#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    int g = 0;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        if (i == 0) {
            g = arr[i];
        } else {
            g = gcd(g, arr[i]);
        }
    }

    for (int i=0;i<n;i++) {
        cout << arr[i] / g;
        if (i != n-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
