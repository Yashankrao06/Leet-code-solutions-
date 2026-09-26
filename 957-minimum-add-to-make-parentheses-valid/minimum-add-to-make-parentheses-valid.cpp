class Solution {
public:
    int minAddToMakeValid(string s) {
       /* int n = s.length();
        int count1=0 ,count2=0;
        for(int i =0 ;i<n;i++){
            if(s[i]=='('){
                count1++;
            }
            if(s[i]==')'){
                count2++;
            }
        }
        int k =0;
        k=abs(count1-count2);
        return k;*/
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == '(' && s[i] == ')') {
                st.pop(); 
            } else {
                st.push(s[i]); 
            }
        }
        return st.size();
    }
};