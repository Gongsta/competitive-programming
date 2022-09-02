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
        string s;
        cin >> s;
        cout << "Case #" << t << ":" << endl;
        string new_s;
        string to_add = "-";
        bool change = true;
        for (auto x: s) {
            if (x != '-') {
                change = false;
                break;
            }
        }
        if (change) {
            to_add = ".";
        }
        for (int i=1;i<n;i++) {
            new_s += to_add;
            cout << s + new_s << endl;

        }
    }

    return 0;
}
