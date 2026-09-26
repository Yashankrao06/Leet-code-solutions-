class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1; 
        stack<char> s2;
        int n1 = s.length();
        int n2 = t.length(); 
        for(int i = 0; i < n1; i++) {
            s1.push(s[i]);
            if(s1.top() == '#') { 
                s1.pop();
                if(!s1.empty()) {
                    s1.pop(); 
                }
            }
        }
        for(int i = 0; i < n2; i++) {
            s2.push(t[i]);
            if(s2.top() == '#') {
                s2.pop();
                if(!s2.empty()) {
                    s2.pop(); 
                }
            }
        }
        return s1 == s2;
    }
};