#include <bits/stdc++.h>

using namespace std;

// Implementation: try the swap on A with the swallest element, which should also work on b.
// if b[i-1] > b[i] then fail
int a[100];
int b[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int> > swaps;
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

        bool works = true;
        
        // Sort the duplicates values in a first such that b in those ranges is sorted. 

        for (int i=0;i<n-1;i++) {
            int curr_max = a[i]; /
            int curr_max_i = i;
            for (int j=i+1;j<n;j++) {
                if (a[j] < curr_max) {
                    curr_max_i = j;
                    curr_max = a[j];
                }
            }
            if (i != curr_max_i) {
                swaps.push_back({i, curr_max_i});
                swap(a[i], a[curr_max_i]);
                swap(b[i], b[curr_max_i]);
            }
            if (i > 0) {
                if (b[i-1] > b[i]) {
                    if (a[i-1] == a[i]) {
                        swap(b[i-1], b[i]);
                        swaps.push_back({i, i-1});
                    } else {
                        works = false;
                        break;
                    }
                }
            }
        }
        
        if (b[n-2] > b[n-1]) {
            if (a[n-2] == a[n-1]) {
                swaps.push_back({n-1, n-2});
            } else {
                works = false;
            }
        }
        if (works) {
            cout << swaps.size() << endl;
            for (auto x: swaps) {
                cout << x.first + 1 << " " << x.second + 1 << endl;
            }

        } else {
            cout << -1 << endl;
        }

        swaps.clear();
    }

    return 0;
}
