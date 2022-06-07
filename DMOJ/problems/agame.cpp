#include <bits/stdc++.h>

using namespace std;

// Hard part: Think of a winning strategy, with a 
int arr[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int total = 0;
    
    for (int i=0;i<N;i++){
        cin >> arr[i];
    }
    int l = 0;
    int r = N-1;
    bool playing = true;
    bool left_max = false;
    while (l<=r) {
        if (arr[l] > arr[r]) {
            left_max = true;
        } else {
            left_max = false;
        }
        if (playing) {
            if (left_max) {
                total += arr[l];
            } else {
                total += arr[r];
            }
        }
        if (left_max) {
            l++;
        } else {
            r--;
        }
         playing = !playing;
    }
    
    cout << total << endl;


    return 0;
}
