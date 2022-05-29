#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, T;
    
    cin >> N >> T;
    int r,c; 
    while (T--){
        if (N % 2 == 1) {
            cout << "1" << endl;
            cout << N/2 + 1 << " " << N/2 + 1 << endl;
        } else {
            cout << "2" << endl;
        }
        while (true) {
            cin >> r >> c;
            if (r == 0 && c == 0) {
                break;
            } else if (r == -1 && c == -1) {
                return 0;
            } else {
                cout << N - r + 1<< " " << N - c + 1 << endl;
            }
        }
    }
    
    return 0;
}
