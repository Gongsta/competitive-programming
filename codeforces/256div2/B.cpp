#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    string t;
    cin >> s >> t;
    map<char, int> m_s;
    map<char, int> m_t;
    for (auto c: s) {
        if (m_s.count(c)) {
            m_s[c]++;
        } else {
            m_s[c] = 1;
        }
    }

    for (auto c: t) {
        if (m_t.count(c)) {
            m_t[c]++;
        } else {
            m_t[c] = 1;
        }
    }

    // Check for automaton
    bool array = true;
    for (auto x: m_s) {
        if (!((m_t.count(x.first)) && (m_t[x.first] == x.second))) {
            array = false;
            break;
        }
    }

    bool automaton = true;
    int j = 0;
    for (int i=0;i<t.length();i++) {
        while (j<s.length()) {
            if (s[j] == t[i]) {
                break;
            }
            j++;
        }
        j++;
        if (j > s.length()) {
            automaton = false;
        }
    }
    bool both = true;
    for (auto x: m_t) {
        if (!(m_s.count(x.first) && m_s[x.first] >= x.second)) {
            both = false;
            break;
        }
    }
    if (array) {
        cout << "array" << endl;
    } else if (automaton) {
        cout << "automaton" << endl;
    } else if (both){
        cout << "both" << endl;
    } else {
        cout << "need tree" << endl;
    }

    return 0;
}
