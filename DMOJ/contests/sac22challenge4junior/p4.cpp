#include <bits/stdc++.h>

using namespace std;

int arr[100002];
int A[100002];
int main() {
    int N;
    long int K;
    long int repeat_modulo = 0;
    bool repeat;
    
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        A[i] = arr[i];
    }
    while (K--) {
        repeat = true;
        repeat_modulo += 1;
        // ohh i got it then
        for (int i=1; i<=N; i++) {
            arr[i] = A[arr[i]];
            if (arr[i] != A[i]) {
                repeat = false;
            }
        }
        // if (repeat) {
        //     K = K % repeat_modulo;
        // }
    }
    for (int i=1; i<=N; i++) {
        cout << arr[i] << " ";
    }
}
