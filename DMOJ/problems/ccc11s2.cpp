#include <bits/stdc++.h>
using namespace std;

char arr[10001];

int main() {
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int total = 0;
    char val;
    for (int i=0;i<N;i++) {
        cin >> val;
        if (val == arr[i]) {
            total++;
        }
    }

    cout << total << endl;
    return 0;
}