#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
int b[1000000];
int c[1000000];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        vector<int> a_pos;
        for (int i=0;i<n;i++) {
            if (s[i] == 'b') {
                if (i != 0) {
                    b[i] = b[i-1] + 1;
                } else {
                    b[i] = 1;
                }
            } else {
                if (i == 0) {
                    b[i] = 0;
                } else {
                    b[i] = b[i-1];
                }
 
            }
        }
        for (int i=0;i<n;i++) {
            if (s[i] == 'c') {
                if (i != 0) {
                    c[i] = c[i-1] + 1;
                } else {
                    c[i] = 1;
                }
            } else {
                if (i == 0) {
                    c[i] = 0;
 
                } else {
                    c[i] = c[i-1];
                }
            }
        }
        for (int i=0;i<n;i++) {
            if (s[i] == 'a') {
                a_pos.push_back(i);
            }
        }
        int ans = -1;
        for (int i=0;i<a_pos.size();i++) {
            for (int j=i+1;j<a_pos.size();j++) {
                if (j - i + 1 > max(c[a_pos[j]] - c[a_pos[i]], b[a_pos[j]] - b[a_pos[i]])) {
                    if (ans == -1) {
                        ans = a_pos[j] - a_pos[i] + 1;
                    } else {
                        ans = min(a_pos[j]-a_pos[i] + 1, ans);
                    }
                    break;
                }
                if (a_pos[j] - a_pos[i] + 1 >= 7) {
                    break;
                }
            }
        }
        cout << ans << endl;
        
 
    }
 
    return 0;
}