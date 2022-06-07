#include <bits/stdc++.h>

using namespace std;

// Binary search Solution to the longest subsequence problem
long int arr[5000];
long int length[5000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int size;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
        
    int l, mid;
    size = 0;
    for (int x: arr) {
        int i=0; 
        int j = size;
        while (i != j) {
            int m = (i+j) / 2;
            if (length[m] < x) {
                i = m +1;
            } else {
                j = m;
            }

        }
        length[i] = x;
        size = max(size, i+1);
        
    }
    cout << size << endl;
    return 0;
}
