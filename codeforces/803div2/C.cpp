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
        ll a[n];
        map<int, int> m;
        m.clear();
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (m.count(a[i])) {
                m[a[i]]++;
            } else {
                m[a[i]] = 1;
            }
        }
        bool works = true;
        if (m.size() > 3 && n > 3) {
            works = false;
        }
        if (n == 3) {
            set<int> targets;
            for (int i=0;i<n;i++) {
                targets.insert(a[i]);
            }
            if (!targets.count(a[0] + a[1] + a[2])) {
                works = false;
            }
        } else {
            auto last = m.end();
            last--;
            if (m.size() == 2) {
                auto last = m.end();
                last--;
                if (m.begin()->first != -last->first || m.begin()->second != last->second || m.begin()->second > 1) {
                    works = false;
                }
            }  else if (m.size() == 3) {
                if (m.begin()->first != -last->first || m.begin()->second != last->second || m.begin()->second > 1) {
                    works = false;
                }
                auto it = m.begin();
                it++;
                if (it->first != 0) {
                    works = false;
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
