#include <bits/stdc++.h>

using namespace std;

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

bool lesserX(P a, P b) {
    if (a.X < b.X) {
        return true;
    } else {
        return false;
    }
}
bool lesserY(P a, P b) {
    if (a.Y < b.Y) {
        return true;
    } else {
        return false;
    }
}
// Check for intersection
// Optimization using a line sweep algorithm (NOT NEEDED)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int xr,yr,xj,yj;
    cin >> xr >> yr >> xj >> yj;
    P r = {xr, yr};
    P j = {xj,yj};

    int n;
    int count = 0;
    cin >> n;
    int x_prev,y_prev,f, x_curr, y_curr, F;
    // At the end, we need to check the break
    while (n--) { // Each n iteration represents 1 building run
        bool intersect = false;
        cin >> f;
        F = f;
        f--;
        if (f>=0) {
            cin >> x_prev >> y_prev;
        }
        P start = {x_prev, y_prev}; // we need to check this at the end
        P prev, curr;
        prev = {x_prev,y_prev};
        while (f > 0) {
            f--;
            cin >> x_curr >> y_curr;
            curr = {x_curr,y_curr};
            
            if ((conj(curr-r)*(curr-j)).Y == 0) { // Curr is on the same line as the r-j line
                //Make sure that curr is located within the r-j line
                // Case 1 or 2, can me in the middle in either the x-axis or y-axis
                if ((lesserX(r,curr) && lesserX(curr,j)) || (lesserX(j, curr) && lesserX(curr,r))) {
                    intersect = true;
                }
                if ((lesserY(r,curr) && lesserY(curr,j)) || (lesserY(j, curr) && lesserY(curr,r))) {
                    intersect = true;
                }
            }
            // Case 3

            bool different_side_1 = false;
            bool different_side_2 = false;
            if ((conj(curr-r)*(curr-j)).Y < 0) {
                if ((conj(prev-r)*(prev-j)).Y > 0) {
                    different_side_1 = true;
                }
            }
            else if ((conj(curr-r)*(curr-j)).Y > 0) {
                if ((conj(prev-r)*(prev-j)).Y < 0) {
                    different_side_1 = true;
                }
            }            
            
            if ((conj(r-curr)*(r-prev)).Y < 0) {
                if ((conj(j-curr)*(j-prev)).Y > 0) {
                    different_side_2 = true;
                }
            }
            else if ((conj(r-curr)*(r-prev)).Y > 0) {
                if ((conj(j-curr)*(j-prev)).Y < 0) {
                    different_side_2 = true;
                }
            }
            if (different_side_1 && different_side_2) {
                intersect = true;
            }

            prev = curr; // update the old prev point
        }
        if (F > 0) {
        // Check one more time for the last with the first element
        if ((conj(start-r)*(start-j)).Y == 0) { // Curr is on the same line as the r-j line
            //Make sure that curr is located within the r-j line
            if ((conj(start-r)*(start-j)).Y == 0) { // start is on the same line as the r-j line
                //Make sure that start is located within the r-j line
                // Case 1 or 2, can me in the middle in either the x-axis or y-axis
                if ((lesserX(r,start) && lesserX(start,j)) || (lesserX(j, start) && lesserX(start,r))) {
                    intersect = true;
                }
                if ((lesserY(r,start) && lesserY(start,j)) || (lesserY(j, start) && lesserY(start,r))) {
                    intersect = true;
                }
            }
        } 
        if (F > 1) { // We need at least 2 values to check the prev
            bool different_side_1 = false;
            bool different_side_2 = false;
            if ((conj(start-r)*(start-j)).Y < 0) {
                if ((conj(prev-r)*(prev-j)).Y > 0) {
                    different_side_1 = true;
                }
            }
            else if ((conj(start-r)*(start-j)).Y > 0) {
                if ((conj(prev-r)*(prev-j)).Y < 0) {
                    different_side_1 = true;
                }
            }            
            
            if ((conj(r-start)*(r-prev)).Y < 0) {
                if ((conj(j-start)*(j-prev)).Y > 0) {
                    different_side_2 = true;
                }
            }
            else if ((conj(r-start)*(r-prev)).Y > 0) {
                if ((conj(j-start)*(j-prev)).Y < 0) {
                    different_side_2 = true;
                }
            }
            if (different_side_1 && different_side_2) {
                intersect = true;
            }
            }
        }
        if (intersect) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
