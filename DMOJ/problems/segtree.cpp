#include <bits/stdc++.h>

using namespace std;


int tree[200001];

int find_min(int l, int r, int N) {
    l += N;
    r += N;

    int min_val = 1 << 30;
    while (l<=r) {
        if (l%2 ==1) min_val = min(min_val, tree[l++]);
        if (r%2 ==0) min_val = min(min_val, tree[r--]);
        l/=2;
        r/=2;
    }
    return min_val;
}
void update(int i, int x, int N) {
    i += N;
    tree[i] = x;
    for (i/=2; i>=1; i/=2) {
        tree[i] = min(tree[2*i], tree[2*i + 1]);
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> tree[N+i];
    }
    // Construct the rest of the Segment Tree
    int curr = N-1;
    while (curr >= 0) {
        tree[curr] = min(tree[2*curr], tree[2*curr + 1]);
        curr--;
    }
    
    int b,c;
    char s;
    while (M--) {
        cin >> s >> b >> c;
        if (s == 'M') {
            update(b, c, N);

        } else {
            cout << find_min(b, c, N) << endl;

        }

    }
    

    return 0;
}
