class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max3 = LONG_MIN; 
        long long max2 = LONG_MIN;
        long long max1 = LONG_MIN;     
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            long long temp = nums[i];
            if (temp == max3 || temp == max2 || temp == max1) {
                continue;
            }
            
            if (temp > max3) { 
                max1 = max2;
                max2 = max3;
                max3 = temp;
            } 
            else if (temp > max2) { 
                max1 = max2;
                max2 = temp;
            } 
            else if (temp > max1) {
                max1 = temp;
            }
        }
        
        return (max1 == LONG_MIN) ? max3 : max1;
    }
};