#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    set<char> consonants;
    set<char> vowels;
    vowels.insert('a');
    vowels.insert('i');
    vowels.insert('u');
    vowels.insert('e');
    vowels.insert('o');
    consonants.insert('k');
    consonants.insert('n');
    consonants.insert('m');
    consonants.insert('r');
    while (T--) {
        string s;
        cin >> s;
        bool works = true;
        for (int i=0;i<s.length();i++) {
            if (vowels.count(s[i])) {
                continue;
            } else if (consonants.count(s[i])) {
                if (i == s.length() -1) {
                    works = false;
                    break;
                } else {
                    if (!vowels.count(s[i+1])) {
                        works = false;
                        break;
                    } else {
                        i++;
                    }
                }
            } else if (s[i] == 'h') {
                if (i == s.length() -1) {
                    works = false;
                    break;
                } else {
                    if (!vowels.count(s[i+1]) || s[i+1] == 'u') {
                        works = false;
                        break;
                    } else {
                        i++;
                    }
                }

            } else if (s[i] == 'f') {
                if (i == s.length() -1) {
                    works = false;
                    break;
                } else {
                    if (s[i+1] != 'u') {
                        works = false;
                        break;
                    } else {
                        i++;
                    }
                }
            } else {
                works = false;
                break;
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
