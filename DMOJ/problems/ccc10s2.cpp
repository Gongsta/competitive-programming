#include <bits/stdc++.h>

using namespace std;

map<string, string> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string A, X;
    while (N--) {
        cin >> A >> X;
        m[X] = A;
    }
    string s;
    cin >> s;
    int i=0; int n=1;
    while (i!=s.length()) {
        string subs = s.substr(i, n);
        if (m.count(subs)) {
            cout << m[subs];
            i = i+n;
            n=1;
        } else {
            n++;
        }
    }

    return 0;
}
