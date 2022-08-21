#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int ask(vector<int> vv) {
    cout << "? " << vv[0] << " " << vv[2] << endl;
    int x;
    cin >> x;
    if (x == 0) {
        cout << "? " << vv[1] << " " << vv[3] << endl;
        cin >> x;
        if (x == 1) return vv[1];
        return vv[3];
    } else if (x == 1) {
        cout << "? " << vv[0] << " " << vv[3] << endl;
        cin >> x;
        if (x == 1) return vv[0];
        return vv[3];
    } else {
        cout << "? " << vv[1] << " " << vv[2] << endl;
        cin >> x;
        if (x == 1) return vv[1];
        return vv[2];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i=1;i<=1 <<n;i++){
            v.push_back(i);
        }
        vector<int> b;
        while (v.size() > 2) {
            while (!v.empty()) {
                vector<int> vv(4);
                vv[0] = v.back();
                v.pop_back();
                vv[1] = v.back();
                v.pop_back();
                vv[2] = v.back();
                v.pop_back();
                vv[3] = v.back();
                v.pop_back();
                
                int win = ask(vv);
                b.push_back(win);
            }
            v = b;
            b.clear();
        }
        if (v.size() == 2) {
            cout << "? " << v[0] << " " << v[1] << endl;
            int x;
            cin >> x;
            if (x == 2) v[0] = v[1];
        }
        cout << "! " << v[0] << endl;
    }

    return 0;
}
