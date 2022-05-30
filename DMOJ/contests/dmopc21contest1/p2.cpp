#include <bits/stdc++.h>

using namespace std;

// 5 4 3 2 1 DONE
// 1 2 3 4 5 -> move 5 first, then 4, then 3, then 2, then 1, then all of them
// 1 2 3 2 1-> move 123, move 2, move 1, move back 21, move 1, move 211 onto 23, move last

/*
  1
2 2
1 3

  1
5 2
6 11



*/
vector<int> v1;
vector<int> v2;
vector<int> operations;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, a;
    for (int i=1;i<=N; i++) {
        cin >> a;
        v1.push_back(a);
    }
    
    bool sorted = true;
    while (true) {
        sorted = true;
        if (v2.size() == 0) {
            for (int i=N-1; i>0; i--) {
                if (v1[i]>v1[i-1]) {
                    sorted = false;
                    v2 = vector<int>(v1[i], v1.end());
                    v1 = vector<int>(v1.start(), v1[i-1]);
                }
            }

        } else {
            if (v1.size() == 0) {
                operations.push_back(-v2.size());
                v1 = v2;
                v2.clear();
            } else {
                for (int i=N-1;i>0;i--) {
                    if (v1.back() <= v2[i]) {
                        if (i==N-1) {
                            temp = vector<int>(v1[i], v1.end());
                            v1 = vector<int>(v1.start(), v1[i-1]);
                            v2.push_back(v1.back());
                            v1.pop_back();
                            operations.push_back(1);
                        }

                    }
                }
            }
            
        }
        
        if (sorted && v1.size() == N) {
            break;
        }
    }
    
    cout << operations.size() << endl;
    for (int op: operations) {
        cout << op << "\n";
    }
    


    return 0;
}
