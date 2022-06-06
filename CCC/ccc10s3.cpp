#include <bits/stdc++.h>

using namespace std;

/*
Thoughts:
Circumference of 1,000,000, but really it can boil down to just being a line that has a wrap around. 
So the maximum distance between a and b is 500,000. 
1. If k>=H, then return 0
2. 


*/

int min_dist(int x, int y) {
    int a = abs(x-y);
    if (a > 500000) {
        return 1000000 - a;
    } else {
        return a;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int H,k;
    cin >> h;

    return 0;
}
