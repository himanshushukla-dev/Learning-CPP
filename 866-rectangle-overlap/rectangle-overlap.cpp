#include <vector>
#include <algorithm>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {

        bool x_overlap = std::max(rec1[0], rec2[0]) < std::min(rec1[2], rec2[2]);
        
        bool y_overlap = std::max(rec1[1], rec2[1]) < std::min(rec1[3], rec2[3]);
        
        return x_overlap && y_overlap;
    }
};