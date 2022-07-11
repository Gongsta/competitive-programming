#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string w;
        cin >> w;
        int p;
        cin >> p;
        int curr_price = 0;
        for (auto x: w) {
            curr_price += x - 'a' + 1;
        }
        string sorted_word = w;
        sort(sorted_word.begin(),sorted_word.end(), greater<char>());
        multiset<char> s;
        int j=0;
        while (curr_price > p) {
            curr_price -= sorted_word[j] - 'a' + 1;
            s.insert(sorted_word[j]);
            j++;
        }
        string final;
        for (auto x: w) {
            if (s.count(x)) {
                s.erase(s.lower_bound(x));
            } else {
                final += x;
            }
        }
        cout << final << endl;
        

    }

    return 0;
}
