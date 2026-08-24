#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums
        std::vector<long long> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Base case: taking all n stones
        long long maxDiff = pref[n - 1];

        // Process backwards from n - 2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            maxDiff = std::max(maxDiff, pref[i] - maxDiff);
        }

        return maxDiff;
    }
};
