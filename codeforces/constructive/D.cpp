#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,k,s;
    cin >> n >> k >> s;
    ll max_dist = (n - 1);
    max_dist = k * max_dist;
    if (max_dist < s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int total_moves = 0;
        int curr = 1;
        int move_dist;
        while (total_moves < k-1) {
            move_dist = s / (k);
            if (curr == 1) {
                curr = curr + move_dist;
                cout << curr << " ";
            } else {
                curr = curr - move_dist;
                cout << curr << " ";
            }
            total_moves++;
        }
        move_dist = s/(k) + s % (k);
        if (curr == 1) {
            curr = curr + move_dist;
            cout << curr << endl;
        } else {
            curr = curr - move_dist;
            cout << curr << endl;
        }
    }

    return 0;
}
