#include <bits/stdc++.h>

using namespace std;

int main() {
    int T,a,b,c,d;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        
        if (((float)b / (float)a) > 1.0 && ((float)d / (float)c) > 1.0 && abs((float) b / (float) a - (float) d / (float)c) > 1e-6) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
