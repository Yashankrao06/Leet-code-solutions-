class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // Open brackets ko stack me daalo
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                if (st.empty()) return false;
                char top = st.top();
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    st.pop(); // Pair match ho gaya
                } else {
                    return false; // Mismatch mila
                }
            }
        }
        return st.empty();
    }
};