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
        string s;
        cin >> s;
        int count_a = 0;
        int count_b = 0;
        string a;
        string b;
        if (s[0] != '1' || s.back() != '1')  {
            cout << "NO" << endl;
        } else {
            int zero_count = 0;
            int one_count = 0;
            for (int i=0;i<n;i++) {
                if (s[i] == '0') {
                    zero_count++;
                } else {
                    one_count++;
                }
            }
            if (zero_count % 2 == 1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                int curr_one = 0;
                bool use_a = false;
                for (int i=0;i<n;i++) {
                    if (s[i] == '1') {
                        if (curr_one < (one_count / 2)) {
                            a.push_back('(');
                            b.push_back('(');
                        } else {
                            a.push_back(')');
                            b.push_back(')');
                        }
                        curr_one++;
                    } else {
                        if (use_a) {
                            a.push_back('(');
                            b.push_back(')');
                        } else {
                            a.push_back(')');
                            b.push_back('(');
                        }
                        use_a = !use_a;
                    }
                }
                cout << a << endl;
                cout << b << endl;

            }

        }

    }

    return 0;
}
