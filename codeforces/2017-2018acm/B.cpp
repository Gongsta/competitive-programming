#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

??
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    bool used[n] = {false};
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int curr = a[0];
    used[0] = true;
    vector<int> temp;
    for (int i=0;i<n;i++) {
        if (a[i] > curr) {
            used[i] = true;
            curr = a[i];
        } else {
            temp.push_back(a[i]);
        }
    }

    }
    return 0;
}
