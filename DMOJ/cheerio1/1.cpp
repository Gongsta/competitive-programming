/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

unordered_set<char> cons;
int main()
{
    cons.insert('a');
    cons.insert('e');
    cons.insert('i');
    cons.insert('o');
    cons.insert('u');
    string s;
    cin >> s;
    bool isCons = false;
    bool valid = true;
    if (cons.count(s[0])) {
        isCons = true;
    }
    for (int i=1;i<s.length();i++) {
        if (isCons && cons.count(s[i])) {
            valid = false;
            break;
        } else if (!isCons && !cons.count(s[i])) {
            valid = false;
            break;
        }
        isCons = !isCons;
    }
    if (valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
