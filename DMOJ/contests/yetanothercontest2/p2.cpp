#include <bits/stdc++.h>

using namespace std;
long int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    long int prev, curr;
    
    // This is a search problem? DP? DFS?
    cout << "? " << 1 << " " << 2 << flush;
    cin >> prev;
    
    cout << "? " << 1 << " " << 3 << flush;
    cin >> curr;
    arr[3] = prev ^ curr;
    prev = curr;

    cout << "? " << 2 << " " << 3 << flush;
    cin >> curr;
    arr[2] = arr[3] ^ curr;
    arr[1] =prev ^ arr[2] ^ arr[3];

    for (int i=4; i<=N; i++) {
        printf("? %d %d", 1, i);
        cout << flush;
        cin >> curr;
        if (curr == -1) {
            return 0;
        }
        arr[i] = curr ^ arr[i-1];
    }
    
    for (int i=1; i<=N; i++) {
        printf("%ld ", arr[i]);
    }
    return 0;
}
