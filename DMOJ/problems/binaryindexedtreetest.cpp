#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

ll tree[100002];
ll arr[100002];

int p(int k) {
    return k&-k;
}
ll sum(int a, int b) {
    ll total = 0;
    for (int i=a; i<=b; i++) {
        total += arr[i];
    }
    return total;

}
int sum_one(int k) {
    int s = 0;
    while (k>=1) {
        s+=tree[k];
        k -= p(k);
    }
    return s;
}
ll sum_a_b(int a, int b) {
    return (sum_one(b) - sum_one(a-1));
}

int get_val(int k){
    return sum_a_b(k, k);
}

void printarr(int N) {
    cout << "printing tree";
    for (int i=1; i<=N; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
}
void add(int k, int x, int N) {
    x = x - get_val(k);
    while (k <= N) {
        tree[k] += x;
        k += p(k);
    }
}
// int countSmaller(int num, int N) {
//     int total = 0;
//     for (int i=N;i>0;i--) {
//         if (tree[i] <= num) {
//             total += i;

//         }
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    for (int i=1; i<=N; i++) {
        tree[i] = sum(i-p(i)+1, i);
    }
    char s;
    int x,v;

    while (M--) {
        cin >> s;
        if (s == 'C') {
            cin >> x >> v;
            add(x,v, N);
        } else if (s=='S') {
            cin >> x >> v;
            cout << sum_a_b(x, v) << endl;
        } else {
            cin >> x;
            int count = 0;
            // Bottleneck, you can fix by binary search... but im too stupid
            for (int i=1; i<=N; i++) {
                if (get_val(i) <= x) {
                    count++;
                }
            }
            cout << count << endl;
            
        }

    }
    

    return 0;
}
