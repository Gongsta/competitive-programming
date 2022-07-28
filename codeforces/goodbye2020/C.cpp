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
        int count = 0;
        bool marked[s.length()];
        marked[0] = false;
        for (int i=1;i<s.length();i++) {
            marked[i] = false;
            if (s[i] == s[i-1]) {
                if (!marked[i-1]) {
                    marked[i] = true;
                    count++;
                } 
            } 
            
            if (i>1 && s[i] == s[i-2] && !marked[i]) {
                if (!marked[i-2]) {
                    count++;
                    marked[i] = true;
                }             } 
        }
        cout << count << endl;

    }

    return 0;
}
