class Solution {
private:
    bool checkbracket(char a, char b) {
        if (a == '(' && b == ')') {
            return true;
        }
        return false;
    }

public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false;

        stack<int> open;
        stack<int> unlocked;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                if (!open.empty()) {
                    open.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.empty() && !unlocked.empty() && open.top() < unlocked.top()) {
            open.pop();
            unlocked.pop();
        }

        return open.empty();
    }
};