#include <vector>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
        // min_len[i] stores the min length of a valid subarray ending at or before index i
        std::vector<int> min_len(n, INF);
        
        int left = 0;
        int current_sum = 0;
        int min_combined_len = INF;
        int best_so_far = INF;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink window if sum exceeds target
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            
            // Valid subarray found
            if (current_sum == target) {
                int curr_len = right - left + 1;
                

                if (left > 0 && min_len[left - 1] != INF) {
                    min_combined_len = std::min(min_combined_len, curr_len + min_len[left - 1]);
                }
                
                best_so_far = std::min(best_so_far, curr_len);
            }
            
            min_len[right] = (right > 0) ? std::min(min_len[right - 1], best_so_far) : best_so_far;
        }
        
        return (min_combined_len >= INF) ? -1 : min_combined_len;
    }
};