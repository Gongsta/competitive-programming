#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    int max_len_suffix = 0;
    int suffix_i = 0;
    int max_len_mid = 0;
    int mid_i = 0;
    for (int i=1;i<z.size();i++) {
        if (z[i] > 0) {
            if (z[i] + i == z.size()) {
                if (z[i] > max_len_suffix) {
                    max_len_suffix = max(max_len_suffix, z[i]);
                    suffix_i = i;

                }
                if (mid_i == suffix_i) {
                    max_len_suffix = z[i];
                    suffix_i = i;

                }
            } 
            if (z[i] > max_len_mid) {
                max_len_mid = max(max_len_mid, z[i]);
                mid_i = i;
            }
        }
    }
    int ans = min(max_len_suffix, max_len_mid);
    if (ans == 0 || suffix_i == mid_i) {
        cout << "Just a legend" << endl;
    } else {
        cout << s.substr(0, ans) << endl;

    }
    

    return 0;
}
