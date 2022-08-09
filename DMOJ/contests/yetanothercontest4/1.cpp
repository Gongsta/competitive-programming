#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a[2*n];
    for (int i=0;i<2*n;i++) {
        cin >> a[i];
    }
    int count = 0;
    for (int i=0;i<n;i++) {
        if (a[i] == a[i+n]) count++;
    }
    cout << count << endl;
    

    return 0;
}
