#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    int a, i;
    char name[5];
    map<int, set<string> > m;

    while (Q--) {
        scanf("%d %d %s", &a, &i, name);
        // cin >> a >> i >> name;
        if (a == 1) {
            if (m[i].count(name)) {
                printf("1\n");
            } else {
                printf("0\n");
            }

        } else {
            if (m[i].count(name) == 0) {
                m[i].insert(name);
            }

        }
    }

    return 0;
}
