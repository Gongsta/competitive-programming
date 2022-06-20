#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double a,b,c,d;
    cin >> a >> b >> c >> d; 
    cout << setprecision(12) << fixed << (a/b)/(1.0-(1.0-a/b)*(1.0-c/d)) << endl;


    return 0;
}
