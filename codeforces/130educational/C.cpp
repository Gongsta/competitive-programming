#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        bool works = true;
        /*
        Insight: a has to be in front of b
        b has to be in front of c
        
        So my solution is right! But I just couldn't implement it. 
        Actually I made the implementation pretty complicated. 
        
        Instead of shifting b in front of a, and c in front of b, I think to think
        about it of always moving b. 
        */
       int s_count = 0;
       int t_count = 0;
       for (int i=0;i<n;i++) {
        if (s[i] == 'b') {
            s_count++;
        }
        if (t[i] == 'b') {
            t_count++;
        }
       }
       if (s_count != t_count) {
            works = false;
       }

       int j = 0;
       for (int i=0;i<n;i++) {
            if (!works) break;
            if (s[i] == 'b') {
                continue;
            }
            while (t[j] == 'b') {
                j++;
            }
            if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)) {
                works = false;
                break;
            }
            j++;
       }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
