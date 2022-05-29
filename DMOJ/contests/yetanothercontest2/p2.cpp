#include <bits/stdc++.h>

using namespace std;
long int arr[100001];
long int cumulative[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    long int prev, curr;
    
    // This is a search problem? DP? DFS?
    cout << "? " << 1 << " " << 2 << endl;
    cin >> prev;
    
    cout << "? " << 1 << " " << 3 << endl;
    cin >> curr;
    arr[3] = prev ^ curr;
    prev = curr;
    cumulative[3] = prev;

    cout << "? " << 2 << " " << 3 << endl;
    cin >> curr;
    arr[2] = arr[3] ^ curr;
    arr[1] = prev ^ arr[2] ^ arr[3];

    for (int i=4; i<=N; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> cumulative[i];
        arr[i] = cumulative[i] ^ cumulative[i-1];
    }
    
    cout << "! ";
    for (int i=1; i<=N; i++) {
        cout << arr[i];
        if (i != N) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
