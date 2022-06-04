#include <bits/stdc++.h>
using namespace std;

int tree_min[200001];
int tree_gcd[200001];

void update_min_and_gcd(int x, int v, int N) {
    v += N;
    tree_min[v] = x;
    tree_gcd[v] = x;
    v /= 2;
    while (v >= 1) {
        tree_min[v] = min(tree_min[2*v], tree_min[2*v+1]);
        tree_gcd[v] = gcd(tree_gcd[2*v], tree_gcd[2*v+1]);
        v/=2;
    }
}

int find_min(int l, int r, int N) {
    l = l + N;
    r = r + N;
    int min_val = 1 << 30;
    while (l<=r) {
        if (l%2 == 1) min_val = min(min_val, tree_min[l++]);
        if (r%2 == 0) min_val = min(min_val, tree_min[r--]);
        l/=2;
        r/=2;
    }
    return min_val;
}

int find_gcd(int l, int r, int N) {
    l = l + N;
    r = r + N;
    int gcd_val = 0;
    while (l<=r) {
        if (l%2 == 1) {
            int temp = gcd(tree_gcd[l], tree_gcd[l+1]);
            l++;
            gcd_val = gcd(temp, gcd_val);
        } 
        if (r%2 == 0) {
            int temp = gcd(tree_gcd[r], tree_gcd[r-1]);
            r--;
            gcd_val = gcd(temp, gcd_val);

        }
        l/=2;
        r/=2;
    }
    return gcd_val;
}

int main() {
    int N, M;

    cin >> N >> M;

    int val;
    for (int i=0;i<N;i++) {
        cin >> val;
        tree_min[N+i] = val;
        tree_gcd[N+i] = val;
    }

    for (int i=N-1;i>=0; i--) {
        tree_min[i] = min(tree_min[2*i], tree_min[2*i + 1]);
        tree_gcd[i] = gcd(tree_min[2*i], tree_min[2*i + 1]);
    }

    char o;
    int l,r;
    while (M--) {
        cin >> o >> l >> r;

        if (o == 'C') {
            update_min_and_gcd(l, r, N);

        } else if (o == 'M') {
            cout << find_min(l, r, N) << endl;
        } else if (o == 'G') {
            cout << find_gcd(l, r, N) << endl;

        } else if (o == 'Q') {
            int val = find_gcd(l,r, N);
            int count = 0;
            for (int i=l; i<=r; i++) {
                if (tree_gcd[i] == val) {
                    count++;
                }
            }
            cout << count << endl;
        }

    }
    return 0;
}