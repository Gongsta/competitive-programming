#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        cin >> a >> b;
        if (a == b) {
            cout << "=" << endl;
        } else if (a[a.length() - 1] == 'S') {
            if (b[b.length() - 1] == 'S') {
                if (a.length() < b.length()) {
                    cout << ">" << endl;
                } else {
                    cout << "<" << endl;
                }
            } else  {
                cout << "<" << endl;
            }
        } else if (a[a.length() - 1] == 'L') {
            if (b[b.length() - 1] == 'L') {
                if (a.length() > b.length()) {
                    cout << ">" << endl;
                } else {
                    cout << "<" << endl;
                }
            } else {
                cout << ">" << endl;
            }
        } else {
            if (b[b.length() - 1] == 'S') {
                cout << '>' << endl;
            } else {
                cout << '<' << endl;
            }
        }
    }

    return 0;
}
