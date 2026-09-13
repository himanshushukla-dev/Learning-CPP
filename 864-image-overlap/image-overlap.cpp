#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> v1, v2;
        
        // Collect coordinates of all 1s in img1 and img2
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) v1.push_back({r, c});
                if (img2[r][c] == 1) v2.push_back({r, c});
            }
        }
        
        // Count frequencies of translation vectors (dr, dc)
        std::map<std::pair<int, int>, int> count;
        int max_overlap = 0;
        
        for (const auto& [r1, c1] : v1) {
            for (const auto& [r2, c2] : v2) {
                std::pair<int, int> vector = {r2 - r1, c2 - c1};
                count[vector]++;
                max_overlap = std::max(max_overlap, count[vector]);
            }
        }
        
        return max_overlap;
    }
};