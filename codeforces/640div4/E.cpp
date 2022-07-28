#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int a[8000];

int prefix_sum(int l, int r) {
    if (l == 0) {
        return a[r];
    } else {
        return a[r] - a[l-1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int total = 0;
        for (int i=0;i<n;i++) {
            int l = 0;
            int r = 0;
            int curr_sum = a[l];
            while (r < n) {
                if (curr_sum == a[i]) {
                    if (l < r) {
                        total++;
                        break;
                    } else {
                        r = l+1;
                        if (r < n) {
                            curr_sum += a[r];
                        }
                    }
                } else if (curr_sum < a[i]) {
                    r++;
                    if (r < n) {
                        curr_sum += a[r];
                    }
                } else {
                    curr_sum -= a[l];
                    l++;
                    if (l > r) {
                        r = l;
                        if (r < n) {
                            curr_sum += a[r];
                        }
                    }
                }
            }
        }

        cout << total << endl;

    }

    return 0;
}
