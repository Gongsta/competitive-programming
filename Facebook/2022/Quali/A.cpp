#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int N, K;
        cin >> N >> K;
        int S[N];
        map<int, int> m;
        string works = "YES";
        for (int i=0;i<N;i++) {
            cin >> S[i];
            m[S[i]]++;
            if (m[S[i]] > 2) {
                works = "NO";
            }
        }
        if (2*K < N) {
            works = "NO";
        }
        cout << "Case #" << t << ": " << works << endl;
    }

    return 0;
}
