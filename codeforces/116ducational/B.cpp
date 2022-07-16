#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll k,n;
        cin >> n >> k;
        ll answer = 0;
        ll i = 1;
        while (i < k) {
            i *= 2;
            answer++;
        }
        answer += ceil((long double)n/(long double)k);
        cout << answer << endl;
    }

    return 0;
}
