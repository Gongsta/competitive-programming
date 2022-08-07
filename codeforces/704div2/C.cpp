#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m,n;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    vector<int> left;
    vector<int> right;
    int j = 0;
    for (int i=0;i<m;i++) {
        while (s[j] != t[i]) j++;
        left.push_back(j);
        j++;
    }
    j = n-1;
    for (int i=m-1;i>=0;i--) {
        while (s[j] != t[i]) j--;
        right.push_back(j);
        j--;
    }
    int ans = 0;
    reverse(right.begin(), right.end());
    for (int i=1;i<m;i++) {
        ans = max(ans, right[i] - left[i-1]);
    }
    cout << ans << endl;
    

    return 0;
}
