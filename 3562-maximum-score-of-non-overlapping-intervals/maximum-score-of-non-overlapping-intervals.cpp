#include <vector>
#include <algorithm>

using namespace std;

class Solution {
struct Interval {
    long long l, r, weight;
    int id;
};

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

 
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

       
        vector<vector<pair<long long, vector<int>>>> dp(5, vector<pair<long long, vector<int>>>(n + 1, {0, {}}));

        for (int i = 1; i <= n; ++i) {
            const auto& current = sorted_intervals[i - 1];


            int low = 0, high = i - 1, prev_idx = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mid > 0 && sorted_intervals[mid - 1].r < current.l) {
                    prev_idx = mid;
                    low = mid + 1;
                } else if (mid == 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            for (int k = 1; k <= 4; ++k) {
 
                dp[k][i] = dp[k][i - 1];


                long long take_weight = current.weight + dp[k - 1][prev_idx].first;
                vector<int> take_indices = dp[k - 1][prev_idx].second;
                take_indices.push_back(current.id);
                sort(take_indices.begin(), take_indices.end());


                if (take_weight > dp[k][i].first) {
                    dp[k][i] = {take_weight, take_indices};
                } else if (take_weight == dp[k][i].first && !take_indices.empty()) {
                    if (dp[k][i].second.empty() || take_indices < dp[k][i].second) {
                        dp[k][i] = {take_weight, take_indices};
                    }
                }
            }
        }

        pair<long long, vector<int>> best_res = {0, {}};
        for (int k = 1; k <= 4; ++k) {
            if (dp[k][n].first > best_res.first) {
                best_res = dp[k][n];
            } else if (dp[k][n].first == best_res.first) {
                if (best_res.second.empty() || (dp[k][n].second.size() > 0 && dp[k][n].second < best_res.second)) {
                    best_res = dp[k][n];
                }
            }
        }

        return best_res.second;
    }
};