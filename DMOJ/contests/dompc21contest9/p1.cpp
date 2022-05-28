#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, max_size, curr;
    int count=0;
    scanf("%d", &N);

    N--;
    N--;
    scanf("%d", &max_size);

    if (max_size <= 1) {
        cout << 0 << endl;
        return 0;

    }
    int temp[max_size - 1];

    for (int i=0; i< max_size - 1; i++) {
        temp[i] = max_size - (i + 1);
    }

    while (N--) {
        scanf("%d", &curr);
        for (int i=0; i < max_size - 1; i++) {
            if (temp[i] == 0) {
                continue;
            } else {
                temp[i] = curr - temp[i];
            }
            if (temp[i] <= 0) {
                temp[i] = 0;
            }
        }
            
    }

    for (int i=0; i< max_size - 1; i++) {
        if (temp[i] > 0) {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}
