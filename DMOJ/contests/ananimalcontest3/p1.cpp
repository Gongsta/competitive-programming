#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C,D;
    
    cin >> A >> B >> C >> D;
    if (B > A && D > C) {
        cout << "Go to the department store" << endl;
    } else if (B > A) {
        cout << "Go to the grocery store" << endl;
    } else if (D > C) {
        cout << "Go to the pharmacy" << endl;
        
    } else {
        cout << "Stay home" << endl;
    }

    return 0;
}
