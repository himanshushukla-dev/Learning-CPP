#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) 
    {
        int n = s.length();
        
        string half = s.substr(0, n / 2);
        
        sort(half.begin(), half.end());
        
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        
        if (n % 2 == 1) 
        {
            return half + s[n / 2] + rev_half;
        } 
        else 
        {
            return half + rev_half;
        }
    }
};