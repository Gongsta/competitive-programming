#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X;
    
    cin >> N >> X;
    
    if ((N-X) % 2 != 0) {
        cout << "-1\n";
    } else {
        if (N % 2 != 0) {
            X -= 1;
        }
        for (int i=1; i<=N; i++) {
            if (i % 2 == 1) {
                cout << "1";
            } else {
                if (X > 0) {
                    X -= 2;
                    cout << "1";
                } else {
                    cout << "0";
                }
            }
            if (i != N) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
        
    }
    return 0;
}
