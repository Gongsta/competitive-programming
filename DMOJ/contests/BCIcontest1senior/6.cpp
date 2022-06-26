#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct rectangle {
    int l;
    int b;
    int r;
    int t;
} typedef rectangle;

int get_area(rectangle rec) {
    return (rec.t - rec.b) * (rec.r - rec.l);
}

intersection() {

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<rectangle> v;
    rectangle rec;
    int l,b,r,t;
    while (M--) {
        cin >> l >> b >> r >> t;
        rec.l =l;
        rec.b = b;
        rec.r = r;
        rec.t = t;

    }
    if (M == 0) 

    return 0;
}
