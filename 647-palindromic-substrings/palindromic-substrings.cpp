class Solution {
public:
    int countSubstrings(string s) {
        int totalCount = 0;
        // Har character ko center maan kar expand karenge
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindromes (Center ek character hai)
            totalCount += countPalindromesAroundCenter(s, i, i);
            // Case 2: Even length palindromes (Center do characters ke beech hai)
            totalCount += countPalindromesAroundCenter(s, i, i + 1);
        }
        return totalCount;
    }
private:
    // Helper function jo center se bahar ki taraf expand karke palindromes count karta hai
    int countPalindromesAroundCenter(const string& s, int left, int right) {
        int count = 0;
        
        // Jab tak pointers bounds mein hain aur characters match kar rahe hain
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++; // Ek valid palindrome substring mil gaya
            left--;  // Left ko aur peeche le jao (Expand)
            right++; // Right ko aur aage le jao (Expand)
        }
        
        return count;
    }
};