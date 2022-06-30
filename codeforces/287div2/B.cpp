#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double r,x,y,x_p,y_p;
    cin >> r >> x >> y >> x_p >> y_p;
    double d = sqrt(pow(x_p - x,2)+ pow(y_p -y,2));
    cout << ceil(d/(2.0 * r)) << endl;
    
    return 0;
}
