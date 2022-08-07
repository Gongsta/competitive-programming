#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,H,M;
        cin >> n >> H >> M;

        int minutes_sleep = 1e9;
        while (n--) {
            int h,m;
            cin >> h >> m;
            if (h < H || (h == H && m < M)) {
                minutes_sleep = min(minutes_sleep, (h * 60 + m) - ((H - 24) * 60 + M));
            } else {
                minutes_sleep = min(minutes_sleep, (h * 60 + m) - (H * 60 + M));
            }
        }
        cout << minutes_sleep / 60 << " " << minutes_sleep % 60 << endl;

    }

    return 0;
}
