#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> vec(2);
        cin >> vec[0];
        cin >> vec[1];
        vector<vector<int>> c(2, vector<int>(n, 0));
        int ans1 = vec[1][n - 1] - '0';
        int ans0 = (vec[0][n - 1] - '0') << 1 + ans1;
        c[1][n - 1] = 1;
        c[0][n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 1; i >= 0; i--) {
                if (i == 1) {
                    ans1 = ((vec[i][j] - '0') << (n - j - 1)) + ans1;
                    // cout << "j " << j << " " << ans1 << endl;
                    c[i][j] = c[i][j + 1];
                } else {
                    if (ans0 == ans1) {
                        c[i][j] = c[i][j + 1] + c[i + 1][j];
                    } else if (ans0 < ans1) {
                        c[i][j] = c[i][j + 1];
                    } else {
                        c[i][j] = c[i + 1][j];
                        ans0 = ans1;
                    }
                    ans0 = ((vec[i][j] - '0') << (n - j)) + ans0;
                }
                // cout << ans0 << " " << ans1 << endl;
            }
        }
        string final_ans;
        for (int i = 0; i <= n; i++) {
            final_ans += '0' + (ans0 & 1);
            ans0 = ans0 >> 1;
        }
        reverse(final_ans.begin(), final_ans.end());
        cout << final_ans << endl;
        cout << c[0][0] << endl;
    }

    return 0;
}
