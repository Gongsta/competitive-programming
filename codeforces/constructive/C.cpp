#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    string s;
    cin >> s;
    int col_counter = 1;
    int row_counter = 1;
    for (int i=0;i<s.length();i++) {
        if (s[i] == '0') {
            cout << '2' << " " << col_counter << endl;
            col_counter++;
            if (col_counter == 5) {
                col_counter = 1;
            }
        } else {
            cout << '1' << " " << row_counter << endl;
            row_counter += 2;
            if (row_counter == 5) {
                row_counter = 1;
            }
        }
    }
    return 0;
}
