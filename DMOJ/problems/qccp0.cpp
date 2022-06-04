#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    float T;
    cin >> N;
    while (N--) {
        cin >> T;
        if (T < 34.0) {
            cout << "Too cold, please try again." << endl; 
        } else if (34.0 <= T && T <= 35.5) {
            cout << "Take a hot bath." << endl;
        }  else if (35.5 < T && T <= 38.0) {
            cout << "Rest if feeling unwell." << endl;
        }  else if (38.0 < T && T <= 39.0) {
            cout << "Take some medicine." << endl;
        }  else if (39.0 < T && T <= 41.0) {
            cout << "Take a cold bath and some medicine." << endl;
        }  else if (41.0 < T && T <= 46.1) {
            cout << "Go to the hospital." << endl;
        }   else if (46.1 < T && T <= 50.0) {
            cout << "Congrats, you have a new world record!" << endl;
        }   else if (50.0 < T) {
            cout << "Too hot, please try again." << endl;
        }
    } 

    return 0;
}