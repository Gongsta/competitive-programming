#include <bits/stdc++.h>

using namespace std;

int main() {
    long int T,a,b,c,d;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        
        if (((b-a) * (d-c)) > (a * c)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
