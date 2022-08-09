#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> v[1000001];
int pointers[1000001];
unordered_map<int, int> m;
unordered_map<int, int> total;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int b[n+1];
    for (int i=1;i<=n;i++) {
        cin >> b[i];
        m[b[i]] = i;
        total[b[i]]++;
        v[b[i]].push_back(i);
    }
    bool works = true;
    for (auto x: m) {
        if (x.first == 1) continue;
        if (!m.count(x.first - 1) && total[x.first] % x.first != 0) {
            works = false;
            break;
        }
    }

    if (works) {
        for (int i=1;i<=n;i++) {
            if (b[i] == 1) {
                cout << i;
            } else {
                if (total[b[i]-1] > 0) {
                    cout << m[b[i]-1];
                } else {
                    pointers[b[i]]++;
                    if (pointers[b[i]] % b[i] == 0) {
                        cout << v[b[i]][pointers[b[i]]-b[i]];
                    } else {
                        cout << v[b[i]][pointers[b[i]]];

                    }
                }
            }
            if (i == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }

    } else {
        cout << -1 << endl;
    }


    return 0;
}
