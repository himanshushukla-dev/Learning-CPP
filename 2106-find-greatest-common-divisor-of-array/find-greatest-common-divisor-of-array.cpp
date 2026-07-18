

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        
        int mn = *std::min_element(nums.begin(), nums.end());
        int mx = *std::max_element(nums.begin(), nums.end());
        
        
        return std::gcd(mn, mx);
    }
};