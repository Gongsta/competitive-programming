#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m; 
    
    int a = 5;
    int a_count = 0;
    a_count = (n - a)/ 4 + 1;
    for (int i=0;i<a_count;i++) {
        cout << "4";
    }
    cout << "5";
    cout << endl;
    for (int i=0;i<=a_count;i++) {
        cout << "5";
    }
    cout << endl;


    return 0;
}
