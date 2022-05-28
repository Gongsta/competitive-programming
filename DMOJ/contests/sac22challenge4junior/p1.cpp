#include <bits/stdc++.h>

using namespace std;

int main() {
    string w;
    cin >> w;
    
    set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('y');

    int total = 0;
    for (auto c: w) {
        if (vowels.count(c)) {
            total += 1;
        }
    }
    
    if (total >= 2) {
        cout << "good\n";
    } else {
        cout << "bad\n";
    }
    return 0;
}
