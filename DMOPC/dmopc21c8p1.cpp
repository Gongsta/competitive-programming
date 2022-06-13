#include <bits/stdc++.h>

using namespace std;

// Incomplete
int arr[500000];
dequeue<int> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    bool match = true;
    for (int i=0;i<N-1;i++) {
        q.push_back(arr[i]);
        if (arr[i] + arr[i+1] < M) {
            match = false;
            for (int j=i+2;j<N;j++) {
                if (arr[i] + arr[j] >= M) {
                    match = true;
                    int temp = arr[j];
                    for (int k=j;k>i;k--) {
                        arr[k] = arr[k-1];
                    }
                    arr[i+1] = temp;
                    break;
                }
            }
            if (!match) {
                break;
            }

        }
        if (!match) {
            break;
        }
    }

    if (!match) {
        cout << -1 << endl;
    } else {
        for (int i=0;i<N;i++) {
            cout << arr[i];
            if (i != N-1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
