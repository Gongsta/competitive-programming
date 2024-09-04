#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int time = stoi(s.substr(0, 2));
        bool night = false;
        if (time >= 12) {
            night = true;
            if (time > 12) {
                time -= 12;
            }
        }
        if (time == 0) {
            time += 12;
        }

        if (time < 10) {
            cout << "0";
        }
        cout << time << ":" << s.substr(3, 2) << " ";
        if (night) {
            cout << "PM" << endl;
        } else {
            cout << "AM" << endl;
        }
    }

    return 0;
}
