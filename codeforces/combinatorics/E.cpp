#include <bits/stdc++.h>

using namespace std;

double expected(double x, double p, int t) {
    if (t == 0) {
        return x;
    } else {
        cout << p * expected(x+1, p, t-1) + (1-p)*expected(x, p, t-1) << endl;
        return p * expected(x+1, p, t-1) + (1-p)*expected(x, p, t-1);
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,t;
    double p;
    cin >> n >> p >> t;
    cout << setprecision(12) << fixed << expected(0,p,t) << endl;

    return 0;
}
