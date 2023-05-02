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
        map<int, int> m;
        map<int, int> target_m;
        int p[n];
        int sorted_p[n];
        for (int i=0;i<n;i++) {
            cin >> p[i];
            m[p[i]] = i;
            sorted_p[i] = p[i];
        }
        sort(sorted_p, sorted_p+n);
        for (int i=0;i<n;i++) {
            target_m[sorted_p[i]] = i;
        }
        int ans = 0;
        vector<int> out_of_place;
        for (int i=0;i<n;i++) {
            if ((m[p[i]] - target_m[p[i]] + k) % k == 0) {
                continue;
            } else {
                out_of_place.push_back(p[i]);
            }
        }
        if (out_of_place.size() == 0) {
            cout << 0 << endl;
        } else if (out_of_place.size() > 2) {
            cout << -1 << endl;
        } else {
            int temp = m[out_of_place[0]];
            m[out_of_place[0]] = m[out_of_place[1]];
            m[out_of_place[1]] = temp;

            bool works = true;
            for (int i=0;i<n;i++) {
                if ((m[p[i]] - target_m[p[i]] + k) % k == 0) {
                    continue;
                } else {
                    works = false;
                    break;
                }
            }

            if (works) {
                cout << 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }


    return 0;
}
