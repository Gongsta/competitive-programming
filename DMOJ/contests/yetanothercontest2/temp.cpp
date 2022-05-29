class Solution {
public:

    int rearrangeCharacters(string s, string target) {
		int total = 0;
		map<char, int> mt;
		map<char, int> ms;
		for (char x: target) {
			if (!mt.count(x)) {
				mt[x] = 1;
			} else {
				mt[x] += 1;
			}
		}
		
		for (char x: s) {
			if (!ms.count(x)) {
				ms[x] = 1;
			} else {
				ms[x] += 1;
			}
		}
		
		
		while (true) {
			for (auto x: mt) {
				if (!ms.count(x.first)) {
					return total;
				}
				ms[x.first] -= x.second;
				if (ms[x.first] < 0) {
					return total;
				}
			}
			total += 1;

		}
		

        

    }
    
};