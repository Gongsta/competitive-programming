#include <bits/stdc++.h>

using namespace std;

int arr[100001];
map<string, int> m;

int main() {
    m["square"] = 1;
    m["circle"] = 2;
    m["triangle"] = 3;
    int N, Q;
    cin >> N >> Q;
    string a,b;
    int i;
    while (Q--) {
        cin >> a >> b >> i;
        if (a == "get") {
            if (arr[i] == m[b]) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (a == "set") {
            if (b == "square") {
                arr[i] = 1;
                
            } else if (b == "circle") {
                arr[i] = 2;

            } else if (b == "triangle") {
                arr[i] = 3;
            }
        }
    }
    return 0;
}
