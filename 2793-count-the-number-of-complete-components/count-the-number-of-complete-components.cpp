#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) 
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        for (int i = 0; i < n; ++i) 
        {
            if (!visited[i]) 
            {
                int vertexCount = 0;
                int totalEdgesInComponent = 0;
                
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) 
                {
                    int curr = q.front();
                    q.pop();
                    
                    vertexCount++;
                    totalEdgesInComponent += degree[curr];

                    for (int neighbor : adj[curr]) 
                    {
                        if (!visited[neighbor]) 
                        {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                if (totalEdgesInComponent == vertexCount * (vertexCount - 1)) 
                {
                    completeComponentsCount++;
                }
            }
        }

        return completeComponentsCount;
    }
};