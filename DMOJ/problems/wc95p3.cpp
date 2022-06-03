#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,N;
    
    
    cin >> t;
    while (t--) {
        cin >> N;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                cout << j << " ";
            }
        }
    }

    return 0;
}
