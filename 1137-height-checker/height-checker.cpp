class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int mismatches = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                mismatches++;
            }
        }
        return mismatches;
    }
};
