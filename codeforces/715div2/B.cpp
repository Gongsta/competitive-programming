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
        string s;
        cin >> s;
        vector<int> T;
        vector<int> M;
        bool works = true;
        for (int i=0;i<n;i++) {
            if (s[i] == 'T') {
                T.push_back(i);
            } else {
                M.push_back(i);
            }
        }
        if (2 * M.size() != T.size())  {
            works = false;
        } else {
            for (int i=0;i<M.size();i++) {
                if (T[i] > M[i] || M[i] > T[i + M.size()]) {
                    works = false;
                    break;
                }
            }
        }
        
        
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
