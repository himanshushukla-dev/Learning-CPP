#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
    
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> result(n);
        int i = 0;
        
    
        while (i < n) {
            int j = i;
            vector<int> indices;
            

            while (j < n && (j == i || sorted_nums[j].first - sorted_nums[j - 1].first <= limit)) {
                indices.push_back(sorted_nums[j].second);
                j++;
            }
            
        
            sort(indices.begin(), indices.end());
            
        
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = sorted_nums[i + k].first;
            }
            
            i = j;
        }
        
        return result;
    }
};