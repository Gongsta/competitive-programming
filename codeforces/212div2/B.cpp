#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m; 
    int arr[m];
    for (int i=0;i<m;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+m);
    int contiguous = 0;
    bool works = true;
    if (arr[0] == 1) {
        works = false;
    }
    for (int i=1;i<m;i++) {
        if (arr[i] - arr[i-1] == 1) {
            contiguous++;
        } else {
            contiguous = 0;
        }
        if (contiguous >= 2) {
            works = false;
            break;
        }
    }
    if (arr[m-1] == n) {
        works = false;
    }
    if (works) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
