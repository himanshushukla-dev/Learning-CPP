#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1000000007;

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) 
        {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> sum_d(n + 1, 0);
        vector<int> cnt_n0(n + 1, 0);
        vector<long long> p(n + 1, 0);

        for (int i = 0; i < n; ++i) 
        {
            int d = s[i] - '0';
            sum_d[i + 1] = sum_d[i] + d;
            
            if (d == 0) 
            {
                cnt_n0[i + 1] = cnt_n0[i];
                p[i + 1] = p[i];
            } 
            else 
            {
                cnt_n0[i + 1] = cnt_n0[i] + 1;
                p[i + 1] = (p[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) 
        {
            int l = q[0], r = q[1];

            long long sd = sum_d[r + 1] - sum_d[l];
            int non_zero_count = cnt_n0[r + 1] - cnt_n0[l];

            long long removed_prefix = (p[l] * pow10[non_zero_count]) % MOD;
            long long x = (p[r + 1] - removed_prefix + MOD) % MOD;

            ans.push_back((x * sd) % MOD);
        }

        return ans;
    }
};