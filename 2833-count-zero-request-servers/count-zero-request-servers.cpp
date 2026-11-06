class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
       
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
    
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        vector<int> serverCount(n + 1, 0);
        int activeServers = 0;
        
        int left = 0, right = 0;
        int numLogs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i].first;
            int origIdx = sortedQueries[i].second;
            int windowStart = qTime - x;
            int windowEnd = qTime;
            

            while (right < numLogs && logs[right][1] <= windowEnd) {
                int serverId = logs[right][0];
                if (serverCount[serverId] == 0) {
                    activeServers++;
                }
                serverCount[serverId]++;
                right++;
            }
            
 
            while (left < numLogs && logs[left][1] < windowStart) {
                int serverId = logs[left][0];
                serverCount[serverId]--;
                if (serverCount[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }
            

            ans[origIdx] = n - activeServers;
        }
        
        return ans;
    }
};