#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int N, K;
        cin >> N >> K;
        int ans = 0;
        int C[N];
        int W[N];
        int max_weight = 0;
        int total_c= 0;
        int total_cookies = 0;
        for (int i=0;i<N;i++) {
            cin >> C[i] >> W[i];
            total_c+= C[i];
            max_weight = max(max_weight, W[i]);
        }
        int total_cookies_less_eq = 0;
        int total_c_less_eq = 0;
        int strictly_lighter = 0;
        for (int i=0;i<N;i++) {
            if (W[i] <= W[0]) {
                total_c_less_eq += C[i];
            }
            if (W[i] < W[0]) {
                strictly_lighter += C[i];
            }
        }
        total_cookies = total_c;
        total_cookies_less_eq = total_cookies_less_eq;
        int numerator = 1;
        int denominator = 1;
        total_cookies_less_eq--; // The final cookie
        for (int i=0;i<K;i++) {
            numerator *= total_cookies_less_eq;
            denominator *= total_cookies;
            total_cookies_less_eq--;
            total_cookies--;
        }

        total_cookies = total_c;

        int num_2 = 1;
        int denom_2 = total_cookies;
        for (int i=0;i<K-1;i++) {
            num_2 *= strictly_lighter;
            denom_2 *= total_cookies;
            strictly_lighter--;
            total_cookies--;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
