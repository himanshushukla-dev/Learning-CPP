#include <vector>
#include <string>

class Solution {
public:
    void backtrack(int open, int close, int n, string current, std::vector<string>& result) {

        if (open == n && close == n) {
            result.push_back(current);
            return;
        }


        if (open < n) {
            backtrack(open + 1, close, n, current + "(", result);
        }

 
        if (close < open) {
            backtrack(open, close + 1, n, current + ")", result);
        }
    }

    std::vector<string> generateParenthesis(int n) {
        std::vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};