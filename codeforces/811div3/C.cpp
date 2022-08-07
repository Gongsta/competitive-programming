#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int s;
        string ans;
        cin >> s;
        int max_num = 9;
        while (s > 0) {
            if (s <= max_num) {
                ans += s +'0';
                s -= s;
            } else {
                s -= max_num;
                ans += max_num + '0';
                max_num--;
            }


        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    }

    return 0;
}
