#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) 
    {
        int totalOnes = 0;
        vector<int> zeroBlocks;
        
        int n = s.length();
        int i = 0;
        
        while (i < n) 
        {
            int j = i;
            while (j < n && s[j] == s[i]) 
            {
                j++;
            }
            int len = j - i;
            if (s[i] == '1') 
            {
                totalOnes += len;
            } 
            else 
            {
                zeroBlocks.push_back(len);
            }
            i = j;
        }
        
        int maxGain = 0;
        for (size_t k = 0; k + 1 < zeroBlocks.size(); ++k) 
        {
            maxGain = max(maxGain, zeroBlocks[k] + zeroBlocks[k + 1]);
        }
        
        return totalOnes + maxGain;
    }
};