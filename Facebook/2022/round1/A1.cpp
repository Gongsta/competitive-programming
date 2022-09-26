#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    for (int t=1;t<=tt;t++) {
        int n,k;
        cin >> n >> k;
        int A[n];
        int B[n];
        for (int i=0;i<n;i++) {
            cin >> A[i];
        }
        for (int i=0;i<n;i++) {
            cin >> B[i];
        }
        bool works = true;
        bool identical = true;
        for (int i=0;i<n;i++) {
            if (A[i] != B[i]) {
                identical = false;
                break;
            }
        }
        if (n == 2) {
            if (A[0] == B[0]) {
                if (k % 2 != 0) {
                    works = false;
                }
            } else {
                if (k % 2 != 1) {
                    works =false;
                }
            }
        } else {
            if (k == 0) {
                if (!identical) {
                    works = false;
                }
            } else {
                vector<int> starting_pos;
                works = false;
                for (int i=0;i<n;i++) {
                    if (A[i] == B[0]) {
                        starting_pos.push_back(i);
                    }
                }
                for (auto pos: starting_pos) {
                    works = true;
                    int i_a = pos;
                    int i_b = 0;
                    int total = 0;
                    while (total != n) {
                        if (A[i_a] != B[i_b]) {
                            works = false;
                            break;
                        } else {
                            i_b++;
                            total++;
                            i_a++;
                            i_a %= n;
                        }
                    }
                    if (works) {
                        break;
                    }
                }
                if (k == 1 && identical) {
                    works = false;
                }
            }
        }
        if (works) {
            cout << "Case #" << t << ": " << "YES" << endl;
        } else {
            cout << "Case #" << t << ": " << "NO" << endl;
        }
    }

    return 0;
}
