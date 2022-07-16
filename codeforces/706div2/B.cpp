#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        set<int> s;
        for (int i=0;i<n;i++) {
            int x; 
            cin >> x;
            s.insert(x);
        }
        int mex = 0;
        for (auto x: s) {
            if (x == mex) {
                mex++;
            } else {
                break;
            }
        }
        while (!s.count(ceil((long double)(mex + *s.rbegin()) / 2.0)) && k > 0) {
            s.insert(ceil((long double)(mex + *s.rbegin()) / 2.0));
            k--;
            if (ceil((long double)(mex + *s.rbegin()) / 2.0) == mex) {
                mex++;
            } else {
                break;
            }
        }

        cout << s.size() << endl;

    }

    return 0;
}
