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
        int a[n];
        map<int, int> m;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for (auto x: m) {
            pq.push({x.second, x.first});
        }
        int count = n;
        while (pq.size() >= 2) {
            auto [count1, x1] = pq.top();
            pq.pop();
            auto [count2, x2] = pq.top();
            pq.pop();
            count1--;
            count2--;
            count-=2;
            if (count2) {
                pq.push({count2, x2});
            }
            if (count1) {
                pq.push({count1, x1});
            }

        }
        cout << count << endl;
    }

    return 0;
}
