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
        set<pair<int, int>> s;
        map<int, int> count;
        vector<pair<int, int>> v;
        bool works = true;
        int a,b;
        while (n--) {
            cin >> a >> b;
            if (a > b) {
                swap(a,b);
            }
            v.push_back({a,b});
            s.insert({a,b});
        }
        /*
        3 conditions must be met:
            1. a != b for all pairs {a,b}
            2. count[a] < 3 && count[b] < 3 for all pairs {a,b}
            3.  for all a1b1, a1b2, b1b2 does not exist
        */


        for (auto x: v) {
            a = x.first;
            b = x.second;
            if (a == b) {
                works = false;
                break;
            }
            count[a]++;
            count[b]++;
            if (count[a] >= 3 || count[b] >= 3) {
                works = false;
                break;
            }
        }
        sort(v.begin(), v.end());
        set<int> s1;
        set<int> s2;
        for (auto x: v) {
            a = x.first;
            b = x.second;
            if (s1.count(a) && s2.count(a)) {
                works = false;
                break;
            }
            if (s1.count(b) && s2.count(b)) {
                works = false;
                break;
            }
            if (s1.count(a)) {
                s2.insert(a);
                if (s2.count(b)) {
                    works = false;
                    break;
                }
                s2.insert(b);
            } else if (s1.count(b)) {
                s2.insert(b);
                if (s2.count(a)) {
                    works = false;
                    break;
                }
                s2.insert(a);
            } else {
                s1.insert(a);
                s1.insert(b);
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
