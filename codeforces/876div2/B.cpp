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
        vector<pair<int, int>> v;
        int a,b;
        for (int i=0;i<n;i++) {
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end(), [](pair<int,int> &p1, pair<int,int> &p2){ return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);});
        // sort(v.begin(), v.end(), greater<pair<int,int>>());
        ll ans = 0;
        int count = 0;
        int curr_num = v[0].first;
        int curr_num_count = 0;
        for (int i=0;i<n;i++) {
            if (v[i].first != curr_num) {
                count = 0;
                curr_num = v[i].first;
            }

            if (v[i].first <= count) {
                continue;
            } else {
                ans+= v[i].second;
                count++;
            }
        }

        cout << ans << endl;
        

    }

    return 0;
}