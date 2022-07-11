#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<int> mem;
        int days = 1;
        for (int i=0;i<s.length();i++) {
            if (mem.count(s[i])) {
                continue;
            } else {
                if (mem.size() < 3) {
                    mem.insert(s[i]);
                } else {
                    days++;
                    mem.clear();
                    mem.insert(s[i]);
                }
            }
        }
        cout << days << endl;

    }

    return 0;
}
