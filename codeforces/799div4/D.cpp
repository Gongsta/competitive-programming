#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return (s == rev);
}
string add_time(string s, int x) {
    int hours = x / 60;
    int mins = x % 60;
    
    int s_hours = stoi(s.substr(0, 2));
    int s_mins = stoi(s.substr(3, 2));
    
    s_hours += hours;
    s_mins += mins;
    if (s_mins >= 60) {
        s_hours += 1;
        s_mins -= 60;
    }
    s_hours = s_hours % 24;
    
    // Convert back to string
    string f;
    if (s_hours < 10) {
        f += "0";
    } 
    f += to_string(s_hours);
    f += ":";
    if (s_mins < 10) {
        f += "0";
    }
    f+= to_string(s_mins);

    return f;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;
        string s1;
        s1 = add_time(s, x);
        int count = 0;
        while (s1 != s) {
            if (is_palindrome(s1)) {
                count++;
            }
            s1 = add_time(s1, x);

        }
        if (is_palindrome(s1)) {
            count++;
        }
        cout << count << endl;

    }

    return 0;
}
