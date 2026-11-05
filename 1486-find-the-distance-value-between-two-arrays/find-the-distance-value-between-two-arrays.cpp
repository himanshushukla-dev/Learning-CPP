#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int count = 0;
        
        for (int x : arr1) {
            // Find the first element in arr2 >= x - d
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // If no element in arr2 falls in [x - d, x + d], increment count
            if (it == arr2.end() || *it > x + d) {
                count++;
            }
        }
        
        return count;
    }
};