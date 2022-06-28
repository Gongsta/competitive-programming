#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    map<int,int> m;
    while (t--) {
        m.clear();
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
            while (a[i] > n) {
                a[i]/= 2;
            }
        }
        sort(a,a+n);
        bool works = true;
        for (int i=0;i<n;i++) {
            if (m.count(a[i])) {
                m[a[i]]++;
            } else {
                m[a[i]] = 1;
            }
        }
        for (int i=1;i<=n;i++) {
            if (m.count(i)) {
                continue;
            } else {
                bool check = false;
                for (auto& x: m) {
                    if (x.first < i || x.second == 1) continue;
                    int temp = x.first;
                    while (temp >= i) {
                        if (temp == i) {
                            check = true;
                        }
                        temp /= 2;

                    }
                    if (check) {
                        x.second--;
                        break;
                    }
                }
                if (!check) {
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
