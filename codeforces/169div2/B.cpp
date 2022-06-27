#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c: s) {
        if (m.count(c)) {
            m[c]++;
        } else {
            m[c] = 1;
        }
    }
    int total = 0;
    for (auto x: m) {
        total += x.second % 2;
    }
    if (total % 2 == 1 || total <= 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
