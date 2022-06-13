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
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        int count = 0;
        for (int i=0;i<n-1;i++) {
            if (arr[i] > arr[i+1]) {
                count++;
                i++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
