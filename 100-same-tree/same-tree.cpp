/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    vector <int> ans1,ans2;
    solve(p,ans1);
    solve(q,ans2);
    return ans1==ans2; 
    }
private:
   void solve(TreeNode* root, vector<int>& ans) {
    if (root == nullptr) {
        ans.push_back(INT_MIN);
        return;
    }
    ans.push_back(root->val);
    solve(root->left, ans);
    solve(root->right, ans);
}
};