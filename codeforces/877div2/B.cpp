#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool valid(int one, int two, int three) {
    if ((one < three && three < two) || (two < three && three < one)) {
        return true;
    }
    return false;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];
        int one_pos = -1;
        int two_pos = -1;
        int ans = 0;
        for (int i=0;i<n;i++) {
            cin >> p[i];
        }
        // Intuition: Maximize distance between 1 and 2
        // swap and count?
        // no swap
        // swap left_pos (1 or 2) with beginning
        // swap right_pos (1 or 2) with end
        if (one_pos < two_pos) {
            if (one_pos > (n - 1 - two_pos)) {
                cout << 1 

            }

        } else {

        }
        



    }

    return 0;
}
