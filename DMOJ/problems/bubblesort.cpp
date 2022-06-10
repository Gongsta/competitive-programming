#include <bits/stdc++.h>

using namespace std;

int arr[21];
void coutarr(int N) {
    for (int i=0;i<N;i++) {
        cout << arr[i];
        if (i!=N-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    coutarr(N);
    for (int i=0;i<N;i++) {
        for (int j=0;j<N-1;j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                coutarr(N);
            }
        }
    }

    return 0;
}
