#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) 
    {
        vector<int> lastIdx(26, 0);
        vector<bool> seen(26, false);
        string result = "";
        
        for (int i = 0; i < s.length(); ++i) 
        {
            lastIdx[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.length(); ++i) 
        {
            char c = s[i];
            if (seen[c - 'a']) continue; 
            while (!result.empty() && result.back() > c && lastIdx[result.back() - 'a'] > i) 
            {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(c);
            seen[c - 'a'] = true;
        }
        
        return result;
    }
};