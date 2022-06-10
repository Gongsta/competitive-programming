#include <bits/stdc++.h>

using namespace std;

int dp[200005]; // Represents of number of 'B' of window k up to index i
int count_B(int x, int y, string pattern) {
    int c= 0;
    for (int i=x;i<=y;i++) {
        if (pattern[i] == 'B') {
            c++;
        }
    }
    return c;
}
int count_x(int x,string pattern) {
    if (pattern[x] == 'B') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string pattern;
    int n,k;
    while (t--) {
        cin >> n >> k;
        cin >> pattern;
        int B_i = 0;
        
        dp[k-1] = count_B(0,k-1, pattern);
        int min_changes = k - dp[k-1];
        for (int i=k;i<n;i++) {
            if (k==1) {
                dp[i] = count_x(i, pattern);
            } else if (k == 2) {
                dp[i] = count_x(i, pattern) + count_x(i-1,pattern);
           } else {
                dp[i] = dp[i-1] - count_x(i-k,pattern) + count_x(i, pattern);
            }
            min_changes = min(min_changes, k - dp[i]);
            
            if (min_changes == 0) {
                break;
            }
        }
        cout << min_changes << endl;

    }

    return 0;
}

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     string pattern;
//     int n,k;
//     while (t--) {
//         cin >> n >> k;
//         cin >> pattern;
//         int B_i = 0;
        
//         dp[0] = 0;
//         int min_changes = k - count_x(0, pattern);
//         for (int i=1;i<=n;i++) {
//             if (pattern[i-1] == 'B') {
//                 dp[i] = dp[i-1] + 1;
//             } else {
//                 dp[i] = 0;
//             }
//             min_changes = min(min_changes, k - dp[i]);
            
//             if (min_changes == 0) {
//                 break;
//             }
//         }
//         cout << min_changes << endl;

//     }

//     return 0;
// }
