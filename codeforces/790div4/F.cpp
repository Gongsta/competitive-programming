#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
int main()
{
    int t;
    cin >> t;
    int n,k;
    while (t--) {
        cin >> n >> k;
        int x;
        m.clear();
        for (int i=0;i<n;i++) {
            cin >> x;
            if (m.count(x)) {
                m[x]++;
            } else {
                m[x] = 1;
            }
        }
        vector<int> toerase;
        for (auto x: m) {
            if (x.second < k) {
                toerase.push_back(x.first);
            }
        }
        for (auto x: toerase) {
            m.erase(x);
        }
        toerase.clear();
        if (m.size() == 0) {
            cout << -1 << endl;
        } else {
            int l = m.begin()->first;
            int r = m.begin()->first;
            int curr_l = l;
            int curr_r = r;
            int longest = 1;
            int curr_longest = 0;
            for (auto x: m) {
                curr_longest++;
                if (curr_longest == 1) {
                    curr_l = x.first;
                }
                if (m.count(x.first+1)) {
                    if (curr_longest +1 > longest) {
                        l = curr_l;
                        r = x.first + 1;
                        longest = curr_longest + 1;
                    }
                } else {
                    curr_longest = 0;
                }
                
            }
            cout << l << " " << r << endl;
            
        }
    }

    return 0;
}