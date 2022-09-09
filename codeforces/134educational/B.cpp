#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool works;
int n,m,sx,sy,d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        works = true;
        cin >> n >> m >> sx >> sy >> d;
        if ((sx+d >= n && sx -d <= 1) || (sy + d >= m && sy -d <= 1) || (sx -d <= 1 && sy -d <= 1) || (sy +d >= m && sx +d >= n)) {
            works = false;
        }
        if (works) {
            cout << n+m-2 << endl;

        } else {
            cout << -1 << endl;
        }

    }

    return 0;
}
