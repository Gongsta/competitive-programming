#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        ll h[n];
        for (int i=0;i<n;i++) {
            cin >> h[i];
        }
        bool works = true;
        // Heights: min: h[i] + k -> max: h[i] + 2k - 1
        // Condition: abs(v[i] - v[i-1]) < k)
        ll min_h = h[0] + k; 
        ll max_h = h[0] + k;
        for (int i=1;i<n;i++) {
            min_h = min_h - k + 1;
            max_h = max_h + k - 1;
            ll new_min_h = max(min_h, h[i] + k);
            ll new_max_h = min(max_h, h[i] + 2*k - 1);
            if ((h[i] + 2*k - 1 < new_min_h) || (h[i] + k > new_max_h) || (new_min_h > new_max_h)) {
                works = false;
                break;
            } else {
                min_h = new_min_h;
                max_h = new_max_h;
            }
        }
        // I forgot to check this stupid condition at the end
        if (h[n-1]+k < min_h || h[n-1] + k > max_h) {
            works = false;
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
