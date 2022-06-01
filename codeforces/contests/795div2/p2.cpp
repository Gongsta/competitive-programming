#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int> > pq;
int arr[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int n, s;
    int curr_val, prev_val;
    int curr_i, prev_i;
    int val;
    cin >> t;
    while (t--) {
        cin >> n;
        // Topological sort? I didn't see it was in a non-decreasing order...
        for (int i=1; i<=n; i++) {
            cin >> val;
            pq.push({val, i});
        }
        if (n==1) {
            cout << "-1" << endl;
            continue;
        }
        int first_i, first_val;
        bool single = true;
        first_i = prev_i = pq.top().second;
        first_val = prev_val = pq.top().first;
        bool error = false;
        pq.pop();
        while (!pq.empty()) {
            curr_i = pq.top().second;
            curr_val = pq.top().first;
            pq.pop();
            if (!error) {
                if (curr_val == prev_val) {
                    arr[curr_i] = prev_i;
                    prev_i = curr_i;
                    single = false;
                } else {
                    if (!single) {
                        arr[first_i] = prev_i;
                        first_i = prev_i = curr_i;
                        first_val = prev_val = curr_val;
                        single = true;
                    } else {
                        error = true;
                    }

                }
            }
        }
        if (!single) {
            arr[first_i] = curr_i;
            single = true;
        } else {
            error = true;
        }

        if (error) {
            cout << "-1" << endl;
        } else {
            for (int i=1; i<=n;i++) {
                cout << arr[i];
                if (i!=n) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
