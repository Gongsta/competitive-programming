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
        string s;
        cin >> s;
        set<string> m;
        for (int i=0;i<s.size()-1;i++) {
            m.insert(s.substr(i, 2));
        }
        cout << m.size() << endl;




    }

    return 0;
}
