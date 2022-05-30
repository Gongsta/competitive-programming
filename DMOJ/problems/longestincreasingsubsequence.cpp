#include <bits/stdc++.h>

using namespace std;

long int arr[1000000];
long int length[1000000] = {0};
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
    cout << size;
    return 0;
}
