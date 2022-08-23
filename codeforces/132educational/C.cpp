#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool check_valid(string &s) {
    int curr = 0;
    for (auto x: s) {
        if (x == '(') {
            curr++;
        } else {
            curr--;
            if (curr < 0) return false;
        }
    }
    if (curr != 0) return false;
    return true;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string greedy_string;
        int total_left =0;
        for (auto x: s) {
            if (x == '(') {
                total_left++;
            }
        }
        int left_count = total_left;
        int n = s.length();
        bool works = true;
        int last_open = -1, first_close = -1;
        for (int i=0;i<s.length();i++) {
            char x = s[i];
            if (x == '(') {
                greedy_string += x;
            } else if (x == ')') {
                greedy_string += ')';
            } else {
                if (left_count < n / 2) {
                    left_count++;
                    greedy_string += '(';
                    last_open = i;
                } else {
                    if (first_close == -1) {
                        first_close = i;
                    }
                    greedy_string += ')';
                }
            }
        }
        if (last_open != -1 && first_close != -1) {
            swap(greedy_string[last_open], greedy_string[first_close]);
            if (check_valid(greedy_string)) {
                works = false;
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
