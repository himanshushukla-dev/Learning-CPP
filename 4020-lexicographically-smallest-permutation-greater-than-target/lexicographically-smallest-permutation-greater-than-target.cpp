#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int matched = 0;
        vector<int> prefix_count = count;
        while (matched < n) {
            int c = target[matched] - 'a';
            if (prefix_count[c] > 0) {
                prefix_count[c]--;
                matched++;
            } else {
                break;
            }
        }

        
        for (int i = matched; i >= 0; i--) {
            
            vector<int> current_count = count;
            bool possible = true;
            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';
                if (current_count[c] > 0) {
                    current_count[c]--;
                } else {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

           
            if (i < n) {
                int target_char = target[i] - 'a';
                for (int c = target_char + 1; c < 26; c++) {
                    if (current_count[c] > 0) {
                        
                        string ans = target.substr(0, i);
                        ans += (char)('a' + c);
                        current_count[c]--;

                       
                        for (int k = 0; k < 26; k++) {
                            while (current_count[k] > 0) {
                                ans += (char)('a' + k);
                                current_count[k]--;
                            }
                        }
                        return ans;
                    }
                }
            }
        }

        return "";
    }
};