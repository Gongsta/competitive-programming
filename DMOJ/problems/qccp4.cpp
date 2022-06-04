#include <bits/stdc++.h>

using namespace std;

// ALMOST FINISH PLZZ https://dmoj.ca/problem/qccp4

int arr[101][101];
int N = 0;
    /*
    1 2  
    3 4

    3 1
    4 2

    4 3
    2 1

    270 degrees
    2 3
    1 4

    */
void rotate(int r1, int c1, int r2, int c2, int x) {
    if (x<0) {
        x += 360;
    }
    if (x == 180) {
        for (int i=1; i<=N/2; i++) {
            for (int j=1;i<=N/2; j++) {
                swap(arr[i][j], arr[N-i][N-j]);
            }
        }
    } else if (x == 90) {
        for (int i=1; i<=N/2; i++) {
            for (int j=1;i<=N/2; j++) {
                arr[i][j] = arr[j][N-i];
            }
        }
    } else if (x == 270) {
        for (int i=1; i<=N/2; i++) {
            for (int j=1;i<=N/2; j++) {
                arr[i][j] = arr[N-j][i];
            }
        }

    }
}
int main() {
    int x,Q;
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    cin >> Q;
    int r1,c1,r2,c2;
    while (Q--) {
        cin >> r1 >> c1 >> r2 >> c2 >> x;
        rotate(r1,c1,r2,c2,x);
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cout >> arr[i][j];
            if (j == N) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }



    



    return 0;
}