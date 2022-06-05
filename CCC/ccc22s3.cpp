#include <bits/stdc++.h>

using namespace std;

/*
Obervations:
1. If K < N, return -1
2. If K == N, return [M, M, ... M] (length K) or actually any number x such that 1 <= x <= M
3. If K > N, you need to consider specific cases
   
   Writing down everything, I think I figured it out 
    
    if K >= 2N, return -1

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    if (K < N) {
        cout << -1 << endl;
    } else if (K == N) {
       for (int i=1; i<=K;i++) {
           cout << K;
           if (i == K) {
               cout << endl;
           } else {
               cout << " ";
           }
       }
    } else { // The main case
        if (K >= 2*N) {
            cout << -1 << endl;
        } else {
            int max_val = K - N;
            if (max_val > M) {
                cout << -1 << endl;
            } else {
                int idx = 0;
                for (int i=1;i<=max_val;i++) {
                    cout << i;
                    idx++;
                    if (idx == N) {
                        cout << endl;
                        break;
                    } else {
                        cout << " ";
                    }
                }
                if (idx != N) {
                    for (int i=max_val-1;i>=1;i--) {
                        cout << i;
                        idx++;
                    if (idx == N) {
                        cout << endl;
                        break;
                    } else {
                        cout << " ";
                    }
                    }

                }                 
                
            }
        }

    }

        

    return 0;
}
