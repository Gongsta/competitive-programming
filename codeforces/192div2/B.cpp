#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    set<int> s;
    while (m--) {
        int a,b;
        cin >> a >> b;
        s.insert(a);
        s.insert(b);
    }
    int star;
    for (int i=1;i<=n;i++) {
        if (!s.count(i)) {
            star = i;
            break;
        }
    }
    cout << n -1 << endl;
    for (int i=1;i<=n;i++) {
        if (i != star) {
            cout << i << " " << star << endl;
        }
    }
    


    return 0;
}
