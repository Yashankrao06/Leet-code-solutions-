class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        
        for(int w : weights){
            low = std::max(low, w);
            high += w;
        }
        
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canship(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
private:
    bool canship(vector<int>& weights, int days, int cap){
        int d = 1, curr = 0;
        for(int w : weights){
            if(curr + w > cap){
                d++;
                curr = w;
            } else {
                curr += w;
            }
        }
        return d <= days;
    }
};