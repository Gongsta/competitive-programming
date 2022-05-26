#include <bits/stdc++.h>

using namespace std;

int main() {
    int T,a,b,c,d;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        
        if (((((float) b / (float)a - 2.0) + ((float) b / (float) a - 1.0) * ((float)d / (float)c - 2.0)) > 0.0) && ((((float) d / (float)c - 2.0) + ((float) d / (float) c - 1.0) * ((float)b / (float)a - 2.0)) > 0.0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
