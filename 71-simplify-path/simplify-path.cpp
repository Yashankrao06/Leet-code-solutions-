class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> v;
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') continue;
            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!v.empty()) {
                    v.pop_back();
                }
            } else {
                v.push_back(temp);
            }
        }
        string result = "";
        for (string dir : v) {
            result += "/" + dir;
        }
        return result.empty() ? "/" : result;
    }
};