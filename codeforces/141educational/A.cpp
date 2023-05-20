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
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a, a+n, greater<int>());
        vector<int> ans;

        queue<int> q;
        int curr_sum = 0;
        bool works = true;
        int i = 0;
        while (ans.size() != n) {
            if (a[i] == curr_sum) {
                q.push(a[i]);
                i++;
            } else {
                ans.push_back(a[i]);
                curr_sum += a[i];
                i++;

                if (!q.empty()) {
                    int val = q.front();
                    q.pop();
                    if (val == curr_sum) {
                        works = false;
                        break;
                    } 
                }
            }

        }
        if (works) {
            cout << "YES" << endl;
            for (int i=0;i<n;i++) {
                cout << ans[i];
                if (i == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }


        } else {
            cout << "NO" << endl;

        }
    

    }

    return 0;
}
