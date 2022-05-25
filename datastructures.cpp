#include <bits/stdc++.h>
using namespace std;

int main() {
    //Dynamic Array (vectors)
    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]
    cout << v[0] << "\n"; // 3
    cout << v[1] << "\n"; // 2
    cout << v[2] << "\n"; // 5
    for (auto x: v) {
        cout << x << "\n";
    }
    // size 10, initial value 0
    vector<int> v(10);


    // size 10, initial value 5
    vector<int> v(10, 5);

}