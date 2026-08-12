#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) 
        {
            count[nums[right]]++;

            while (count[nums[right]] > k) 
            {
                count[nums[left]]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};