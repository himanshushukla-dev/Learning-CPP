
class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k == n (Only 1 subarray exists)
        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = std::max(max_val, num);
            }
            return max_val;
        }

        // Count frequency of elements in nums
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Case 2: k == 1 (Numbers occurring exactly once in nums)
        if (k == 1) {
            int ans = -1;
            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = std::max(ans, num);
                }
            }
            return ans;
        }

        // Case 3: 1 < k < n (Only outer elements nums[0] or nums[n-1] can qualify)
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }

        return ans;
    }
};