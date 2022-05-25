#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    string d;
    cin >> N >> d;
    if (N % 2 == 0) {
        if (d == "left") {
            cout << "right";

        } else {
            cout << "left";
        }

    } else {
        if (d == "left") {
            cout << "left";

        } else {
            cout << "right";
        }
    }
    
    return 0;
}