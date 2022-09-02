#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        vector<string> p1;
        vector<string> p2;
        vector<string> p3;
        map<string, int> m;
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            string s;
            cin >> s;
            m[s]++;
            p1.push_back(s);
        }
        for (int i=0;i<n;i++) {
            string s;
            cin >> s;
            m[s]++;
            p2.push_back(s);
        }
        for (int i=0;i<n;i++) {
            string s;
            cin >> s;
            m[s]++;
            p3.push_back(s);
        }
        int p1_score = 0;
        int p2_score = 0;
        int p3_score = 0;
        for (int i=0;i<n;i++) {
            if (m[p1[i]] == 1) {
                p1_score += 3;
            } else if (m[p1[i]] == 2) {
                p1_score += 1;
            }
            if (m[p2[i]] == 1) {
                p2_score += 3;
            } else if (m[p2[i]] == 2) {
                p2_score += 1;
            }
            if (m[p3[i]] == 1) {
                p3_score += 3;
            } else if (m[p3[i]] == 2) {
                p3_score += 1;
            }
        }
        cout << p1_score << " " << p2_score << " " << p3_score << endl;
    }

    return 0;
}
