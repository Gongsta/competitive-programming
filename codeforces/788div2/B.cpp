#include <bits/stdc++.h>

using namespace std;

unordered_set<char> letters;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        int k;
        cin >> n >> s;
        cin >> k;
        char l;
        letters.clear();
        for (int i=0;i<k;i++) {
            cin >> l;
            letters.insert(l);
        }
        int best = 0, curr=0;
        for (int i=0;i<s.length();i++) {
            if (letters.count(s[i])) {
                best = max(best, curr);
                curr = 1;
            } else {
                curr++;
            }
        }
        cout << best << endl;

    }

    return 0;
}
