#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int k;
    cin >> k;
    int a[26];
    int max_val = 0;
    for (int i=0;i<26;i++) {
        cin >> a[i];
        max_val = max(a[i], max_val);
    }
    ll final = 0;
    for (int i=0;i<s.length();i++) {
        final += (i+1) * a[s[i] - 'a'];
    }
    for (int i=s.length();i<s.length()+k;i++) {
        final += (i+1) * max_val;
    }
    cout << final << endl;


    return 0;
}
