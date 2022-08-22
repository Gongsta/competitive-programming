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
        map<int, int> m;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        vector<int> b;
        vector<int> temp;
        for (auto x: m) {
            while (m[x.first] > 0) {
                if (m[x.first] == 1) {
                    b.push_back(x.first);
                } else {
                    temp.push_back(x.first);
                }
                m[x.first]--;
            }
        }
        b.insert(b.end(), temp.begin(), temp.end());
        for (int i=0;i<n;i++) {
            cout << b[i];
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}
