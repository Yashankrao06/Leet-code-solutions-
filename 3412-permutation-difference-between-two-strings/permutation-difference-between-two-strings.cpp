#include <string>
#include <vector>
#include <cmath>
class Solution {
public:
    int findPermutationDifference(std::string s, std::string t) {
        int char_indices[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            char_indices[s[i] - 'a'] = i;
        }
        int total_difference = 0;
        for (int i = 0; i < t.length(); ++i) {
            total_difference += std::abs(char_indices[t[i] - 'a'] - i);
        }
        return total_difference;
    }
};