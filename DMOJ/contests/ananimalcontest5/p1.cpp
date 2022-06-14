#include <bits/stdc++.h>

using namespace std;

int arr[200000];
bool visited[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    int count = 0;
    for (int i=0;i<N-1;i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int j = i+1;
        while (j<N && (visited[j] || (arr[i] + arr[j]) % 2 != 0)) {
            j++;
        }
        if (j >= N) continue;
        visited[j] = true;
        count++;
    }
    
    cout << count << endl;


    return 0;
}
