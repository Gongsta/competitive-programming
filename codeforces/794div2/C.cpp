#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    vector<int> final;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        bool works = true;
        final.clear();

        if (n % 2 == 1) {
            works = false;
        } else {
            for (int i=0;i<n/2;i++) {
                final.push_back(arr[i]);
                final.push_back(arr[i + n/2]);
            }
        }
        for (int i=0;i<final.size();i++) {
            if (final[i] == final[i+1]) {
                works = false;
                break;
            }
        }
        if (!works) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i=0;i<final.size();i++) {
                cout << final[i];
                if (i!= final.size() - 1) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }

        }
    }

    return 0;
}
