#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) 
    {
        int M = *max_element(nums.begin(), nums.end()), MOD = 1e9 + 7;
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) 
        {
            auto next_dp = dp;
            for (int g1 = 0; g1 <= M; ++g1) 
            {
                for (int g2 = 0; g2 <= M; ++g2) 
                {
                    if (!dp[g1][g2]) continue;
                    int n1 = g1 ? std::gcd(g1, x) : x;
                    int n2 = g2 ? std::gcd(g2, x) : x;
                    next_dp[n1][g2] = (next_dp[n1][g2] + dp[g1][g2]) % MOD;
                    next_dp[g1][n2] = (next_dp[g1][n2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        for (int g = 1; g <= M; ++g) ans = (ans + dp[g][g]) % MOD;
        return ans;
    }
};