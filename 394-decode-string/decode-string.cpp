class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string currentStr = "";
        int k = 0;  
        for (char ch : s) {
            // Digit build karo
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            // '[' milne par state stack me save karo
            else if (ch == '[') {
                counts.push(k);
                result.push(currentStr);
                
                // Reset for the content inside '['
                k = 0;
                currentStr = "";
            }
            // ']' milne par decode karke expand karo
            else if (ch == ']') {
                int count = counts.top(); counts.pop();
                string prevStr = result.top(); result.pop();
                
                // Decode string by repeating currentStr 'count' times
                string expanded = "";
                for (int i = 0; i < count; i++) {
                    expanded += currentStr;
                }
                
                // Combine with previous context
                currentStr = prevStr + expanded;
            }
            //  Normal alphabet character
            else {
                currentStr += ch;
            }
        }
        
        return currentStr;
    }
};