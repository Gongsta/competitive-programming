#include <bits/stdc++.h>

using namespace std;

bool can(vector<int>& v, int mid) {
    int k = v.size();
    int x = k - mid;
    for (int i=0;i<=mid;i++) {
        int l = v[i];
        int r = v[i+x-1];
        if (r - l + 1 -x <= mid) {
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> pos;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }
        int l = 0;
        int r = pos.size();
        while (r - l > 1) {
            int mid = (l+r) / 2;
            if (can(pos, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (pos.size() == 0 || pos[pos.size()-1] - pos[0] == pos.size()  - 1) {
            cout << 0 << endl;

        } else {
            cout << r << endl;
        }
        

    }

    return 0;
}
