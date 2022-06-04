#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    int row[M+1] = {0};
    int col[N+1] = {0};

    int x;
    char s;
    int total = 0;
    while (K--) {
        cin >> s >> x;
        if (s == 'R') {
            row[x] += 1;
            
        } else if (s == 'C') {
            col[x] += 1;
            }

    }
    for (int i=1; i<=M;i++) {
        for (int j=1;j<=N;j++) {
            if ((row[i] + col[j]) % 2 == 1) {
                total++;
            }
        }
    }
    cout << total << endl;


    return 0;
}