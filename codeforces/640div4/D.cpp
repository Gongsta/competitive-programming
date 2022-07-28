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
        int seq[n];
        for (int i=0;i<n;i++) {
            cin >> seq[i];
        }
        int moves = 1;
        int a = seq[0];
        int b = 0;
        int l = 1;
        int r = n - 1;
        bool alice = false;
        int min_candy = seq[0];
        while (l <= r) {
            int curr_candy = 0;
            if (alice) {
                while (curr_candy <= min_candy && l <= r) {
                    a += seq[l];
                    curr_candy += seq[l];
                    l++;
                }
                moves++;
            } else {
                while (curr_candy <= min_candy && l <= r) {
                    b += seq[r];
                    curr_candy += seq[r];
                    r--;
                }
                moves++;
            }
            min_candy = curr_candy;
            alice = !alice;
        }
        cout << moves << " " << a << " " << b << endl;

    }

    return 0;
}
