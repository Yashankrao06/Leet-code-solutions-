class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLength=0;
        if(n<3){
            return 0;
        }
        int i = 1;
        while (i < n - 1) {
            
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;
                
                
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }
                
               
                while (right < n - 1 && arr[right + 1] < arr[right]) {
                    right++;
                }
                
                
                maxLength = max(maxLength, right - left + 1);
                
                
                i = right;
            } else {
                i++;
            }
        }
        
        return maxLength;
    }
        
};