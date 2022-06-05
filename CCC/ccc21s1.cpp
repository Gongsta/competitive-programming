#include <bits/stdc++.h>

using namespace std;

int arr[10005];
int main() {

    int N;
    cin >> N;
    long long int total = 0;
    for (int i=1;i<=N+1;i++) {
        cin >> arr[i];
    }
    int w;
    for (int i=1; i<=N;i++) {
        cin >> w;
        total += (arr[i]+ arr[i+1])*w;
    }
    cout << fixed << total / 2.0 << endl;
    return 0;
}