#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
    
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            if (first[charIdx] == -1) {
                first[charIdx] = i;
            }
            last[charIdx] = i;
        }

 
        vector<pair<int, int>> validIntervals;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int left = first[i];
            int right = last[i];
            bool isValid = true;

            for (int j = left; j <= right; ++j) {
                int charIdx = s[j] - 'a';
                
                if (first[charIdx] < left) {
                    isValid = false;
                    break;
                }
                right = max(right, last[charIdx]);
            }

            if (isValid) {
                validIntervals.push_back({right, left});
            }
        }


        sort(validIntervals.begin(), validIntervals.end());

 
        vector<string> result;
        int prevRight = -1;

        for (const auto& interval : validIntervals) {
            int right = interval.first;
            int left = interval.second;

            if (left > prevRight) {
                result.push_back(s.substr(left, right - left + 1));
                prevRight = right;
            }
        }

        return result;
    }
};