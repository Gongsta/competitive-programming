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
        vector<int> a;
        vector<int> b;
        int val;
        for (int i=0;i<n;i++) {
            cin >> val;
            a.push_back(val);
        }
        for (int i=0;i<n;i++) {
            cin >> val;
            b.push_back(val);
        }
        vector<int>::iterator it;
        for (int i=0;i<n;i++) {
            it = lower_bound(a.begin(), a.end(), b[i]);
            cout << *it - b[i] << endl;
        }
        for (int i=0;i<n;i++) {
            it = lower_bound(a.begin(), a.end(), b[i]);
            cout << *it - b[i] << endl;
        }

    }

    return 0;
}
