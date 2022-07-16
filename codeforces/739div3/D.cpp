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
        string s = to_string(n);
        int min_dist = s.length() + 1;
        for (int i=0;i<=60;i++) {
            ll val = (long long) 1 << i;
            string val_string = to_string(val);
            int count = 0;
            int p = 0;
            string temp = s;
            for (int j=0;j<val_string.length();j++) {
                if (p == temp.length()) {
                    count++;
                    temp.push_back(val_string[j]);
                }
                while (temp[p] != val_string[j]) {
                    p++;
                    count++;
                    if (p == temp.length()) {
                        count++;
                        temp.push_back(val_string[j]);
                    }
                } 
                p++;
            }
            count += temp.length() - p;
            min_dist = min(min_dist, count);
        }
        cout << min_dist << endl;
    }

    return 0;
}
