#include <bits/stdc++.h>

using namespace std;

// not fully my solution.. taken heavily from the way tourist implemented his
int a[105];
int b[105];
pair<int,int> p[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            cin >> b[i];
        }
        for (int i=0;i<n;i++) {
            p[i] = {a[i], b[i]};
        }
        sort(a, a+n);
        sort(b, b+n);
        
        vector<pair<int,int>> swaps;
        bool works = true;
        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                if (p[j] == make_pair(a[i], b[i])) {
                    swap(p[i],p[j]);
                    if (i != j) {
                        swaps.push_back({i, j});
                    }
                    break;
                }
            }
            if (p[i] != make_pair(a[i],b[i])) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << swaps.size() << endl;
            for (auto i: swaps) {
                cout << i.first + 1 << " " << i.second + 1 << endl;
            }

        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
