#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        string s;
        cin >> s;
        auto arr = new int[s.length()][26];
        for (int i=0;i<s.length();i++) {
            for (int j=0;j<26;j++) {
                if (i == 0) {
                    if (j == s[i] - 'a') {
                        arr[i][j] = 1;
                    } else {
                        arr[i][j] = 0; 
                    }
                } else {
                    if (j == s[i] - 'a') {
                        arr[i][j] = arr[i-1][j] + 1;
                    } else {
                        arr[i][j] = arr[i-1][j];
                    }
                }
            }
        }

        int n;
        cin >> n;
        int ans = 0;
        while (n--) {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            int middle = (x+y)/2;
            if ((y-x) % 2  == 1) continue;
            int num_even = 0;
            int num_odd = 0;
            for (int i=0;i<26;i++) {
                int curr_sum_1 = 0;
                int curr_sum_2 = 0;
                if (x == 0) {
                    curr_sum_1 = arr[middle][i];
                    curr_sum_2 = arr[y][i] - arr[middle-1][i];
                } else {
                    curr_sum_1 = arr[middle][i] - arr[x-1][i];
                    curr_sum_2 = arr[y][i] - arr[middle-1][i];
                }
                if (s[middle] == ('a' + i)) { // Double counting
                    if (abs(curr_sum_1 - curr_sum_2) == 0) {
                        num_odd++;
                    } else if (abs(curr_sum_1 - curr_sum_2) == 1) {
                        num_even++;
                    } else {
                        num_odd = -1;
                        break;
                    }
                } else {
                    if (abs(curr_sum_1 - curr_sum_2) == 0) {
                        num_even++;
                    } else if (abs(curr_sum_1 - curr_sum_2) == 1) {
                        num_odd++;
                    } else {
                        num_odd = -1;
                        break;
                    }
                }
            }
            if (num_odd == 1) {
                ans++;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
