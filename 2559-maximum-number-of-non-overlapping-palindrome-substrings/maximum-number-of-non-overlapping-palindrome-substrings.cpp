#include <string>
#include <algorithm>

class Solution {
public:
    int maxPalindromes(std::string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; // Tracks the end index of the last chosen palindrome

        for (int i = 0; i < n; ++i) {
            // Check odd-length palindromes centered at i
            // and even-length palindromes centered between i and i + 1
            for (int len : {k, k + 1}) {
                int left, right;
                
                if (len % 2 == 1) { // Odd length
                    left = i - len / 2;
                    right = i + len / 2;
                } else { // Even length
                    left = i - (len / 2 - 1);
                    right = i + len / 2;
                }

                // Ensure bounds and no overlap with the previously selected palindrome
                if (left > last_end && right < n) {
                    if (isPalindrome(s, left, right)) {
                        count++;
                        last_end = right;
                        break; // Move to the next potential starting position
                    }
                }
            }
        }
        return count;
    }

private:
    bool isPalindrome(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};