#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,L,S;
    cin >> N >> L >> S;
    int a,b,s;
    while (N--) {
        cin >> a >> b >> s;
        if (!m.count(a)) {
            m[a] = m.lower_bound(a) + s;
        } else {
            m[a-1] = m[a];
            m[a] = m[a-1] + s;
        }
        if (!m.count(b)) {
            m[b] = m.upper_bound(b) + s;
            m[b] = m[b-1] + s;
        }
    }
    
    
    
    return 0;
}
