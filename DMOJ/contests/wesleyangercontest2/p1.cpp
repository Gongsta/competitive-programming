#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string day;
    
    cin >> day;
    // distance between Christmas and Halloween is 25 + 30 = - 55 days
    // 55 / 7 = - 56 + 1. So 1 day after
    if (day == "Monday") {
        cout << "Tuesday" << endl;
    }
    if (day == "Tuesday") {
        cout << "Wednesday" << endl;
    }
    if (day == "Wednesday") {
        cout << "Thursday" << endl;
    }
    if (day == "Thursday") {
        cout << "Friday" << endl; 
        }
    if (day == "Friday") {
        cout << "Saturday" << endl;
    }
    if (day == "Saturday") {
        cout << "Sunday" << endl;
    }
    if (day == "Sunday") {
        cout << "Monday" << endl;
    }
    return 0;
}
