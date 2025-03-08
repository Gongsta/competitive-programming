/*
[5,1,2,3,6,8,1,5]


prefix sum:
O(n) update, O(1) lookup

O(log n) update, O(log n) lookup.
*/

#include <iostream>
#include <vector>

using namespace std;

int prefix[100000];
int prefix_sum(int i, int j) {
    if (i == 0) {
        return prefix[j];
    }
    return prefix[j] - prefix[i - 1];
}

int main() {
    vector<int> arr = {5, 1, 2, 3, 6, 8, 1, 5};
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = arr[i] + prefix[i - 1];
    }
    cout << prefix_sum(0, 4) << endl;
}
