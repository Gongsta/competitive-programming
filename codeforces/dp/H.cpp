#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int s[n];
    int c[n];
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }
    for (int i=0;i<n;i++) {
        cin >> c[i];
    }

    vector<int> pairs[n];
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (s[j] > s[i]) {
                if (pairs[i].empty()) {
                    pairs[i].push_back(j);
                } else {
                    if (c[j] < c[pairs[i][0]])  {
                        pairs[i][0] = j;
                    }
                }
            }
        }
    }
    int min_cost = 1 << 30;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (pairs[j].empty() || s[j] <= s[i]) continue;
            int min_val = c[pairs[j][0]];
            min_cost = min(min_cost, c[i] + c[j] + min_val);
        }
    }
    if (min_cost >= 1 << 30) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }
    return 0;
}
