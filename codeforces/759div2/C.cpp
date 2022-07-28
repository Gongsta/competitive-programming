#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        ll x[n];
        for (int i=0;i<n;i++) {
            cin >> x[i];
        }
        sort(x, x+n);
        bool reverse = false;

        ll dist = 0;
        ll dist1 = 0;
        ll curr_bags = 0;
        ll curr_bags1 = 0;

        dist1 = abs(x[n-1]);
        curr_bags1 = k;
        for (int i=n-1;i>=0;i--) {
            if (curr_bags1 == 0) {
                curr_bags1 = k;
                dist1 += 2 * abs(x[i]);
            }                         
            
            curr_bags1--;
            if (i != 0) {
                if (curr_bags1 == 0 && abs(x[i-1] > abs(x[i]))) {
                    curr_bags1 = k;
                    dist1 += 2 * abs(x[i]);
                }
                dist1 += x[i] - x[i-1];
            }
        }

        dist = abs(x[0]);
        curr_bags = k;
        for (int i=0;i<n;i++) {
            if (curr_bags == 0) {
                curr_bags = k;
                dist += 2 * abs(x[i]);
            } 
            curr_bags--;
            if (i != n-1) {
                if (curr_bags == 0 && abs(x[i+1] > abs(x[i]))) {
                    curr_bags = k;
                    dist += 2 * abs(x[i]);
                }
                dist += x[i+1] - x[i];
            }
        }


        cout << min(dist, dist1) << endl;


    }

    return 0;
}
