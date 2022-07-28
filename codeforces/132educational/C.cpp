#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        s[0] = '(';
        s[n-1] = ')';
        int l = 0;
        int r = n-1;
        bool works = true;
        int questions[n];
        questions[0] = 0;
        for (int i=0;i<n;i++) {
            if (i != 0) {
                questions[i] = questions[i-1];
            } else {
                questions[i] = 0;
            }
            if (s[i] == '?') {
                questions[i]++;
            }
        }
        while (l <= r) {
            if (s[l] == ')' || s[l] == '?') {
                l++;
                continue;
            }
            if (s[r] == '(') {
                r--;
                continue;
            }
            if (s[l] == '(') {
                while (s[r] != ')') {
                    r--;
                    if (r < l) {
                        break;
                    }
                }
            }
            if (r < l) {
                break;
            }
            if (s[l] == '(' &&  s[r] == ')') {
                if (l == 0) {
                    if (questions[r] > 1) {
                        works = false;
                        break;
                    }
                } else {
                    if (questions[r] - questions[l-1] > 1) {
                        works = false;
                        break;
                    }
                }
                l++;
                r--;
                if (!works) {
                    break;
                }
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
