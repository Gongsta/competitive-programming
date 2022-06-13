#include <bits/stdc++.h>

using namespace std;

vector<char> p0[20];
vector<char> p1[20];
int duplicates[20];
// -97
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        for (int i=0;i<20;i++) {
            p0[i].clear();
            p1[i].clear();
            duplicates[i] = 0;
        }
        long long int total = 0;
        int n;
        cin >> n;
        string s;
        while (n--) {
            cin >> s;
            if (s[0] == s[1]) {
                duplicates[(int)s[0]-97] = 1;
            } else {
                p0[(int)s[0] - 97].push_back(s[1]);
                p1[(int)s[1] - 97].push_back(s[0]);
            }
        }
        for (int i=0;i<20;i++) {
            long long int curr = 1;
            if (p0[i].size() + duplicates[i] > 1) {
                curr= p0[i].size() + duplicates[i];
                total += (curr) * (curr - 1) / 2;
            }
            if (p1[i].size() + duplicates[i] > 1) {
                curr = p1[i].size() + duplicates[i];
                total += (curr) * (curr - 1) / 2;
            }
        }
        cout << total << endl;

    }

    return 0;
}
