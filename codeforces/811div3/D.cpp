#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int n;
        cin >> n;
        string s[n];
        map<int, int> m;
        map<int, int> ans;
        for (int i=0;i<n;i++) {
            cin >> s[i];
        }
        for (int i=0;i<n;i++) {// for each substring
            for (int j=0;j<t.length();j++) { // Go over the start
                pair<int, int> p;
                p.first = j;
                p.second = -1;
                for (int k=0;k<s[i].length();k++) {
                    if (s[i][k] == t[j+k]) {
                        p.second = j+k;
                    } else {
                        break;
                    }
                }
                if (p.second == j + s[i].length() - 1) {
                    if (m.count(p.first)) {
                        if (p.second > m[p.first]) { // There is a better substring
                            m[p.first] = p.second;
                            ans[p.first] = i;
                        }
                    } else {
                        m[p.first] = p.second;
                        ans[p.first] = i;
                    }
                }
            }
        }
        int latest_start = 0;
        vector<int> options;
        vector<pair<int, int>> answer;
        bool works = true;
        bool found = false;
        for (auto x: m) {
            // cout << "start" << x.first << " " << latest_start << endl;
            if (x.first > latest_start) {
                if (options.empty()) {
                    works = false;
                    break;
                }
                int latest_finish = -1;
                int string_i = -1;
                int best_start = -1;
                for (auto o: options) {
                    if (m[o] > latest_finish) {
                        best_start = o;
                        string_i = ans[o];
                        latest_finish = m[o];
                    }
                }
                answer.push_back({string_i, best_start});
                options.clear();
                latest_start = latest_finish + 1;
                if (latest_start == t.length()) {
                    found = true;
                    break;
                }
                if (x.first <= latest_start) {
                    options.push_back(x.first);
                }
            } else {
                options.push_back(x.first);
            }
        }

        if (!found) {
            if (options.empty()) {
                works = false;
            }

            int latest_finish = -1;
            int string_i = -1;
            int best_start = -1;
            for (auto o: options) {
                if (m[o] > latest_finish) {
                    best_start = o;
                    string_i = ans[o];
                    latest_finish = m[o];
                }
            }
            answer.push_back({string_i, best_start});
            options.clear();
            latest_start = latest_finish + 1;
            if (latest_start != t.length()) {
                works = false;
            }
        }
        if (m.empty() && !t.empty()) {
            works =false;
        }
        if (works) {
            cout << answer.size() << endl;
            for (auto x: answer) {
                cout << x.first + 1 << " " << x.second + 1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
