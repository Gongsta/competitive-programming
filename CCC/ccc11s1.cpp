#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int count_t = 0;
    int count_s = 0;
    string s;
    cin >> N;
    getline(cin, s);

    while (N--) {
        getline(cin, s);
        count_t += count(s.begin(), s.end(), 't');
        count_t += count(s.begin(), s.end(), 'T');
        
        count_s += count(s.begin(), s.end(), 's');
        count_s += count(s.begin(), s.end(), 'S');

    }

    if (count_s >= count_t) {
        cout << "French" << endl;
    } else {
        cout << "English" << endl;
    }


    return 0;
}