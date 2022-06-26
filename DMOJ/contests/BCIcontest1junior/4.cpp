#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
/*
// 1996 if works then its just the number of permutations
// 1 996 if works then its 1 + number of permutations for 996
// 1 9 96
// 1 9 9 6 ...

But then you also have to consider 19
// 19 9 6
*/
int prefix[10001];

ll sum(int a, int b) {
    if (a > b) {
        return 0;
    }
    if (a == 0) {
        return prefix[b];
    } else {
        return prefix[b] - prefix[a-1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N,M;
    cin >> N >> M;
    string num;
    cin >> num;
    int total = 0;
    for (ll i=0;i<num.length();i++) {
        if (i == 0) {
            prefix[i] = num[i] - '0';
        } else {
            prefix[i] = prefix[i-1] + num[i] - '0';
        }
    }
    if (sum(0, N-1) <= M) {
        total++;
    }
    for (ll i=2;i<=5;i++) {
        for (int j=i-1;j<N;j++) {
            if (sum(0, j-i) + sum(j+1, N-1) + stoi(num.substr(j-i+1, i)) <= M) {
                // cout << sum(0, j-i) << endl;
                // cout << sum(j+1,N-1) << endl;
                // cout << stoi(num.substr(j-i+1, i)) << endl;
                total++;
            } 
        }
    }
    cout << total << endl;


    return 0;
}
