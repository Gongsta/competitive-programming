#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int  n,x_0,y_0;
    cin >> n >> x_0 >> y_0;
    vector<double> slopes;
    int extra= 0;
    while (n--) {
        int x,y;
        cin >> x >> y;
        if (x-x_0 != 0) {
            double slope = (double)(y-y_0) / (double)(x-x_0);
            slopes.push_back(slope);
        } else {
            extra = 1;
        }
    }
    sort(slopes.begin(), slopes.end());
    int count;
    if (slopes.size() > 0) {
        count = 1;
    } else {
        count = 0;
    }
    for (int i=1;i<slopes.size();i++) {
        if (slopes[i] - slopes[i-1] > numeric_limits<double>::epsilon()) {
            count++;
        }
    }
    cout << count + extra << endl;
    return 0;
}
