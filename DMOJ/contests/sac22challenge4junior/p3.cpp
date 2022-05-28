#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,A;
    cin >> N >> A;
    float A_neg = A - 360;
    int best_idx = 1;
    float best_angle_diff = 1000;
    float x,y;
    float angle;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        angle = atan2(y, x) * 180.0 / 3.1415926;
        if (abs(angle - A) < best_angle_diff) {
            best_idx = i + 1; 
            best_angle_diff = abs(angle-A);
        } else if (abs(angle - A_neg) < best_angle_diff) {
            best_idx = i + 1; 
            best_angle_diff = abs(angle-A_neg);

        }
    }
    
    cout << best_idx << endl;
    return 0;
}
