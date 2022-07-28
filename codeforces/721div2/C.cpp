#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        map<int, int> m;
        map<int, int> first;
        map<int, int> last;
        ll sum = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            m[a[i]]++;
            if (m[a[i]] == 1) {
                first[a[i]] = i;
                last[a[i]] = i;
            } else {
                last[a[i]] = i;
            }
            if (m[a[i]] > 2) {
                sum += last[a[i]] - first[a[i]] + sum;
            } else if (m[a[i]] == 2) {
                sum+= sum + 1;
            }
        }

        cout << sum << endl;


    }

    return 0;
}
