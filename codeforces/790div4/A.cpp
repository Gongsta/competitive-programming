#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int num1 = int(s[0]) + int(s[1]) + int(s[2]);
        int num2 = int(s[3]) + int(s[4]) + int(s[5]);
        if (num1 == num2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
