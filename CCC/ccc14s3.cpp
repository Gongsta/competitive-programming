#include <bits/stdc++.h>

using namespace std;

/*
Find the rule -> the stack has to keep decreasing when you insert it into the branch

Stack data structure
*/
stack<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, T, x;
    cin >> T;
    while (T--) {
        bool Y = true;
        while (!s.empty()) {
            s.pop();
        }
        cin >> N;
        while (N--) {
            cin >> x;
            s.push(x);
        }
        
        stack<int> branch_queue;
        int lake = 1; // Represents the value we want to send to lake
        while (!s.empty()) {
            int x = s.top(); s.pop();
            if (x == lake) {
                lake++;
            } else {
                if (!branch_queue.empty()) {
                    if (x > branch_queue.top()) {
                        Y = false;
                        break;
                    } else {
                        branch_queue.push(x);
                    }
                } else {
                    branch_queue.push(x);
                }
            }
            // Process the branch queue
            while (!branch_queue.empty()) {
                if (branch_queue.top() == lake) {
                    branch_queue.pop();
                    lake++;
                } else {
                    break;
                }
            }
        }
        if (Y) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }


    return 0;
}
