#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        vector<int> A = nums;
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        
        int m = A.size();
        int max_log = log2(m) + 1;
        
        vector<vector<int>> dp(m, vector<int>(max_log));
        
        for (int i = 0; i < m; ++i) 
        {
            auto it = upper_bound(A.begin(), A.end(), A[i] + maxDiff);
            int j = distance(A.begin(), it) - 1;
            dp[i][0] = j;
        }
        
        for (int k = 1; k < max_log; ++k) 
        {
            for (int i = 0; i < m; ++i) 
            {
                dp[i][k] = dp[dp[i][k - 1]][k - 1];
            }
        }
    
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) 
        {
            int u = q[0], v = q[1];
            
            if (u == v) 
            {
                ans.push_back(0);
                continue;
            }
            if (nums[u] == nums[v]) 
            {
                ans.push_back(1);
                continue;
            }
            
            int val_u = nums[u];
            int val_v = nums[v];
            if (val_u > val_v) swap(val_u, val_v);
            
            int idx_u = lower_bound(A.begin(), A.end(), val_u) - A.begin();
            int idx_v = lower_bound(A.begin(), A.end(), val_v) - A.begin();
            
            int steps = 0;
            int curr = idx_u;
            
            for (int k = max_log - 1; k >= 0; --k) 
            {
                if (dp[curr][k] < idx_v) 
                {
                    steps += (1 << k);
                    curr = dp[curr][k];
                }
            }
            
            if (dp[curr][0] >= idx_v) 
            {
                ans.push_back(steps + 1);
            } 
            else 
            {
                ans.push_back(-1); 
            }
        }
        
        return ans;
    }
};