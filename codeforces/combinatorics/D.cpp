#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll count_factors(ll l, ll r, ll p) {
    if (r < p) return 0;
    ll start = (l / p) * p;
    if (start < l) {
        start += p;
    }
    if (start > r) return 0;
    return ((r - start) / p + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,p;
    vector<pair<int,int>> s;
    cin >> n >> p;
    int l,r;
    ll possibilities, valid;
    for (int i=0;i<n;i++) {
        cin >> l >> r;
        s.push_back({l, r});
    }
    double expected = 0, sub_expected;
    pair<int, int> pp;
    for (int i=1;i<n;i++) {
         // I am ALMOST there
        // Count the number of factors from l to r
        possibilities = s[i].second - s[i].first + 1;
        possibilities *= s[i-1].second - s[i-1].first + 1;
        valid = count_factors(s[i].first, s[i].second, p);
        sub_expected = double(valid) / double(possibilities);
        cout << sub_expected << endl;
        expected += 1.0/(n) * (sub_expected);
    }
    possibilities = s[0].second - s[0].first + 1;
    possibilities *= s[n-1].second - s[n-1].first + 1;
    valid = count_factors(s[0].first * s[n-1].first, s[0].second * s[n-1].second, p);
    sub_expected = double(valid) / double(possibilities);
    expected += 1.0/(n) * (sub_expected);
    // TODO: Check between 0 and n
    cout << setprecision(12) << fixed << expected << endl;

    return 0;
}
