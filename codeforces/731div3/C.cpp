#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int k,n,m;
        cin >> k >> n >> m;
        int a[n];
        int b[m];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<m;i++) {
            cin >> b[i];
        }
        vector<int> actions;
        int a_p = 0;
        int b_p = 0;
        bool works = true;
        int val;
        while (a_p < n || b_p < m) {
            if (a_p == n) {
                val = b[b_p];
                b_p++;
            } else if (b_p == m) {
                val = a[a_p];
                a_p++;
            } else if (a[a_p] > k) {
                val = b[b_p];
                b_p++;
            } else if (b[b_p] > k) {
                val = a[a_p];
                a_p++;
            } else {
                val = a[a_p];
                a_p++;
            }
            if (val == 0) {
                k++;
            }
            if (val > k) {
                works = false;
                break;
            } else {
                actions.push_back(val);
            }
        }
        if (works) {
            for (int i=0;i<actions.size();i++) {
                cout << actions[i];
                if (i != actions.size() -1) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
            
        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}
