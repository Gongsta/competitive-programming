#include <bits/stdc++.h>

using namespace std;

float arr[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, D, K, X, P;
    cin >> N >> D >> K >> X;

    for (int i=1;i <=N; i++) {
        cin >> arr[i];
    }
    cin >> P;
    
    bool win;
    while (K >= 0) {
        win = true;
        for (int i=1; i<=N;i++){
            if (arr[i] >= P) {
                arr[i] = floor(arr[i] * (100.0 - X)/100.0);
                win = false;
                K--;
            }

        }
        if (win && K >= 0) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    return 0;
}
