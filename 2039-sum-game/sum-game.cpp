#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int half = n / 2;
        
        int left_sum = 0, left_q = 0;
        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') {
                left_q++;
            } else {
                left_sum += num[i] - '0';
            }
        }
        
        int right_sum = 0, right_q = 0;
        for (int i = half; i < n; ++i) {
            if (num[i] == '?') {
                right_q++;
            } else {
                right_sum += num[i] - '0';
            }
        }
        
        int total_q = left_q + right_q;
        
        // If total '?' is odd, Alice gets the last move and always wins
        if (total_q % 2 != 0) {
            return true;
        }
        
        // Bob wins if and only if the sum difference perfectly offsets the '?' deficit
        return (left_sum - right_sum) != (right_q - left_q) * 9 / 2;
    }
};