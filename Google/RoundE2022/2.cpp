#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int n;
        cin >> n;
        vector<int> R;
        vector<int> mentors;
        map<int, int> m;
        for (int i=0;i<n;i++) {
            int x;
            cin >> x;
            R.push_back(x);
            if (m.count(R[i])) {
                m[R[i]]++
            } else {
                m[R[i]] = 1;
            }
        }
        mentors = R;
        sort(mentors.begin(), mentors.end());
        int ans = 0;
        cout << "Case #" << t << ": ";
        for (int i=0;i<n;i++) {
            vector<int>::iterator it;
            it = lower_bound(mentors, mentors.end(), 2*R[i]);
            if (it == mentors.end() || m[*it] == 1) {
                cout << -1;
            }
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }

        }
    }

    return 0;
}
