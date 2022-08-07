#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// This problem really wasn't that hard, it was more that I had an problem with precision
// and my comparison for power was not working properly. Make sure to cast to (ll) when you use pow
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll k;
    cin >> k;
    ll min_len = 1;
    for (ll i=2;i<=100;i++) {
        if (pow(i, 10) > k) break;
        min_len = i;
    }
    ll curr = pow(min_len, 10);
    ll biggest_i = 0;
    for (ll i=0;i<=10;i++) {
        biggest_i = i;
        if ((ll)(pow(min_len, 10-i) * pow(min_len+1,i)) >= k)  {
            break;
        }
        
    }
    string cf = "codeforces";
    string s;
    for (int i=0;i<biggest_i;i++) {
        s += string(min_len+1, cf[i]);
    }
    for (int i=biggest_i;i<10;i++) {
        s += string(min_len, cf[i]);
    }
    cout << s << endl;

    return 0;
}
