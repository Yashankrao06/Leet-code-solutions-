#include <vector>
#include <string>

class Solution {
public:
    void backtrack(std::vector<std::string>& result, std::string current_str, int open_count, int close_count, int max_pairs) {
        // Base case: If the current string reaches the maximum length allowed (2 * n)
        if (current_str.length() == max_pairs * 2) {
            result.push_back(current_str);
            return;
        }

        // Decision 1: We can add an opening parenthesis if we haven't used all 'n' of them
        if (open_count < max_pairs) {
            backtrack(result, current_str + "(", open_count + 1, close_count, max_pairs);
        }

        // Decision 2: We can add a closing parenthesis if it won't exceed the number of opening ones
        if (close_count < open_count) {
            backtrack(result, current_str + ")", open_count, close_count + 1, max_pairs);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
