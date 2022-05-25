#include <bits/stdc++.h>

using namespace std;

int main() {
    int t1, t2;
    int len = 2;
    cin >> t1 >> t2;
    
    int t3 = t1 - t2;
    
    while (t3 >= 0) {
        len++;
        int temp = t3;
        t3 = t2 - t3;
        t1 = t2;
        t2 = temp;
    }
    
    cout << len << endl;

    return 0;
}
