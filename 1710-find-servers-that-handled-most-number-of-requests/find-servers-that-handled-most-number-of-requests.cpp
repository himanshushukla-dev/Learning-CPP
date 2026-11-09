#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        vector<int> requestCount(k, 0);

        for (int i = 0; i < arrival.size(); ++i) {
            long long currTime = arrival[i];
            int duration = load[i];

            // Free up servers whose tasks have finished by the current arrival time
            while (!busy.empty() && busy.top().first <= currTime) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no servers are available, drop the request
            if (available.empty()) {
                continue;
            }

            int preferred = i % k;
            auto it = available.lower_bound(preferred);

            // If no server >= preferred is available, wrap around to 0
            if (it == available.end()) {
                it = available.begin();
            }

            int assignedServer = *it;
            available.erase(it);

            // Assign task to the server
            busy.push({currTime + duration, assignedServer});
            requestCount[assignedServer]++;
        }

        int maxRequests = 0;
        for (int count : requestCount) {
            maxRequests = max(maxRequests, count);
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};