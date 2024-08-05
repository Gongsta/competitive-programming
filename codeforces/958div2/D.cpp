#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;
/*
The problem is basically DP on trees. You need to find a set of vertices that produces the maximum sum, and then remove those vertices, and repeat
until you run out of vertices..?
- Is that the optimal solution? Because you can always just do it in 2 sweeps (because all trees are bipartite).
- First question: how do you remove the enemies to minimize cost? 1-time is ok, but do you guarantee the same property if you repeat the process?
I don't think you can guarantee that

Assume by contradiction that there is a removal process which minimizes even more damage lost. Let a_k be the first monster that was not removed by greedy 
but was removed by optimal solution
- If this monster is 


*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << (1 >> 2) << endl;
    int t;
    cin >> t;
    while (t--) {
    }

    return 0;
}
