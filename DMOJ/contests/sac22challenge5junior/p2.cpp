#include <bits/stdc++.h>

using namespace std;

int main() {
    int won=0;
    int N;
    scanf("%d", &N);
    int a,b;
    while (N--) {
        cin >> a >> b;
        if (a > b) {
            won += 1;
        }

    }

    printf("%d\n", won);

    return 0;
}
