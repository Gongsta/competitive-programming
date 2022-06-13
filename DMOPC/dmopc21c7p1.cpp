#include <bits/stdc++.h>

using namespace std;

int arr[1500][1500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    bool works = true;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                if (i == 0) {
                    if (j == 0) {
                        arr[i][j] = 1;
                    } else {
                        arr[i][j] = arr[i][j-1] + 1;
                    }
                } else {
                    if (j != 0) {
                        arr[i][j] = max(arr[i-1][j] + 1, arr[i][j-1] + 1);
                    } else {
                        arr[i][j] = arr[i-1][j] + 1;
                    }
                }
            } 
            if (j!=0 && arr[i][j-1] >= arr[i][j]) {
                works = false;
            } 
            if (i!= 0 && arr[i-1][j] >= arr[i][j]) {
                works = false;
            }
        }
    }
    
    if (works) {
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                cout << arr[i][j];
                if (j == M-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }

    } else {
        cout << -1 << endl;
    }

    return 0;
}
