#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    int len;

    cin >> x;
    // Loop total test cases
    for (int _=0; _<x; _++) {
        int cost = 0;
        cin >> len;
        int arr[len];
        // Store values to array
        for (int j=0; j<len; j++) {
            cin >> arr[j]; 
        }

        // LOGIC: Sort Array
        int j;
        for (int i=0; i<len-1; i++) {
            j = i;
            int min = *min_element(arr+i, arr+len);
            for (int k=i; k<len; k++) {
                if (min == arr[k]) {
                    j = k;
                }
            }
            /*
            int temp;
            for (int k=i; k<j/2; k++) { //I was writing my own function for reverse...
                temp = arr[k];
                arr[k] = arr[j-k];
                arr[j-k] = temp;
            }
            */
           reverse(arr+i, arr+j+1); //begin() points to the first element, end() points to the last element + 1, but for array just do normally, idk why i had to do j+1...
           cost += (j-i+1);
        }

        cout << "Case #" << _+1 << ": " << cost << "\n";
    }

}
