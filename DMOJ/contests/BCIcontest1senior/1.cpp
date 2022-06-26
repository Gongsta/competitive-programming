#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int b[10000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    map<int, int> m;
    for (int i=0;i<N*N;i++) {
        cin >> b[i];
        if (m.count(b[i])) {
            m[b[i]]++;
        } else {
            m[b[i]] = 1;
        }
    }
    vector<int> a;
    for (auto x: m) {
        if (x.second % 2 == 1) {
            a.push_back(x.first/2);
        }
    }
    for (int i=0;i<N;i++) {
        cout << a[i];
        if (i != N-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
