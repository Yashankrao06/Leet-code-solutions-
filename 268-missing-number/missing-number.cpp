class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int miss = n; 
        for (int i = 0; i < n; i++) {
            miss ^= i ^ nums[i];
        }
        
        return miss;
    }
};