#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,mx;
    cin >> n >> mx;
    map<string, string> m;
    while (mx--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        if (s2.length() < s1.length()) {
            m[s1] = s2;
            m[s2] = s2;
        } else {
            m[s1] = s1;
            m[s2] = s1;
        }
    }
    while (n--) {
        string s;
        cin >> s;
        cout << m[s];
        if (n == 0) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}
