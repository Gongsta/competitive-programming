#include <bits/stdc++.h>

using namespace std;

float arr[1002];
int total_streams;
void mergearr(int a) {
    float new_val = arr[a] + arr[a+1];
   for (int i=a+1;i<=total_streams;i++)  {
      arr[i] = arr[i+1];
   }
   arr[a] = new_val;
   arr[total_streams] = 0;
   total_streams--;
}

void splitarr(int a, float b){
    total_streams++;
    float left = arr[a] * (b / 100.0);
    float right = arr[a] * (1.0 - b/100.0);
    for (int i=total_streams;i>a;i--) {
        arr[i] = arr[i-1];
    }
    arr[a] = left;
    arr[a+1] = right;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    total_streams = n;
    int x,a,b;
    while (true) {
        cin >> x;
        if (x == 77) {
            for (int i=1;i<=total_streams;i++) {
                cout << round(arr[i]) << " ";
            }
            break;
        } else if (x == 99) {
            cin >> a >> b;
            splitarr(a,b);

        } else {
            cin >> a;
            mergearr(a);
        }

    }
    
    return 0;
}