// INCOMPLETE
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int diff[capacity.size()];
        for (int i=0; i<capacity.size(); i++) {
            diff[i] = capacity[i] - rocks[i];
        }
        
        bool full;
		long int minimum;
		int minimum_i;

		// If you have 6 rocks, and there are 3 more bags each needing 6 rocks, you shouldn't distribute it evenly.
		// You gotta distribute greedily
		// Store a sorted index...
        while (additionalRocks) {
			minimum=10000000000;
            for (int i=0; i<capacity.size(); i++) {
                if (diff[i] > 0) {
					if (diff[i] < minimum) {
						minimum = diff[i];
						minimum_i = i;
					}
                } 
			}
			
			if (minimum==10000000000) {
				break;
			} else {
				if (minimum > additionalRocks) {
					break;
				} else {
					diff[minimum_i] -= minimum;
					additionalRocks -= minimum;
				}
			}
        }
            
        int count = 0;
        for (int i=0; i<capacity.size(); i++) {
            if (!diff[i]) {
                count += 1;
            }
        }
        
    return count;
    }
};