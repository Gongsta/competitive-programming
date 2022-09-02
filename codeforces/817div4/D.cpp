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
        string s;
        cin >> s;
        int curr = 0;
        int curr_sum = 0;
        for (int i=0;i<n;i++) {
            if (s[i] == 'R') {
                curr_sum += n - i - 1;
            } else {
                curr_sum += i;
            }
        }
        for (int i=0;i<n;i++) {
            while (curr <= (n-1)/2) {
                if (s[curr] == 'L') {
                    curr_sum -= curr;
                    curr_sum += n - curr - 1;
                    s[curr] = 'R';
                    break;

                } else if (s[n-curr-1] == 'R' && (n-curr-1 != curr)) {
                    s[n-curr-1] = 'L';
                    curr_sum -= curr;
                    curr_sum += n- curr -1;
                    break;
                } else {
                    curr++;
                }
            }
            cout << curr_sum;
            if (i == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }

    }

    return 0;
}
