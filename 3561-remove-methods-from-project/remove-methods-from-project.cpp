#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> bad(n, false);
        queue<int> q;
        q.push(k);
        bad[k] = true;

        while (!q.empty()) 
        {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) 
            {
                if (!bad[next]) 
                {
                    bad[next] = true;
                    q.push(next);
                }
            }
        }
        for (const auto& e : invocations) 
        {
            if (!bad[e[0]] && bad[e[1]]) 
            {
                bad.assign(n, false); 
                break;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) 
        {
            if (!bad[i]) ans.push_back(i);
        }
        return ans;
    }
};