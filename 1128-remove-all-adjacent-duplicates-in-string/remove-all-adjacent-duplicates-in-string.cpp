class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(!st.empty() && st.top() == s[i]) {
                st.pop(); // Duplicate mila, remove kar do
            } else {
                st.push(s[i]); // Unique hai, push kar do
            }
        }
        // Stack se string build karo
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // Stack me characters reverse order me hote hain
        reverse(ans.begin(), ans.end());
        return ans;
    }
};