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
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        vector<string> rotations;
        for (int i=0;i<n;i++) {
            int min_val = a[i];
            int min_idx = i;
            for (int j=i;j<n;j++) {
                if (a[j] < min_val) {
                    min_idx = j;
                    min_val = a[j];
                }
            }
            if (min_idx != i) {
                rotate(a+i, a+min_idx, a+n);
                string rotation;
                rotation =  to_string(i+1) + " " + to_string(n) + " " + to_string(min_idx - i);
                rotations.push_back(rotation);
            }
        }
        cout << rotations.size() << endl;
        for (auto s: rotations) {
            cout << s << endl;
        }
    }

    return 0;
}
