class Solution {
private: 
    bool palindromecheck(string s , int left , int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left =0;
        int right=n-1;
        while(left<right){
            if(s[left]!=s[right]){
                return (palindromecheck(s ,left+1,right)||palindromecheck(s ,left,right-1));
            }
            left++;
            right--;
        }
        return true;
    }
};