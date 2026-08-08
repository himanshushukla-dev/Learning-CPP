#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) 
    {
        int n = word1.length(), m = word2.length();
        
        vector<int> last(m, -1);
        int ptr = n - 1;
        
        for (int j = m - 1; j >= 0; --j) 
        {
            while (ptr >= 0 && word1[ptr] != word2[j]) 
            {
                ptr--;
            }
            if (ptr < 0) break;
            last[j] = ptr--;
        }

        vector<int> ans;
        int i = 0;
        bool changed = false;

        for (int j = 0; j < m; ++j) 
        {
            while (i < n) {
                bool is_match = (word1[i] == word2[j]);
                int next_avail = (j + 1 < m) ? last[j + 1] : n;

                if (is_match || (!changed && i < next_avail)) 
                {
                    if (!is_match) changed = true;
                    ans.push_back(i++);
                    break;
                }
                i++;
            }

            if (ans.size() != j + 1) return {};
        }

        return ans;
    }
};