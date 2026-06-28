class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            res.push_back(path);
        } else {
            dfs(root->left, targetSum - root->val, path);
            dfs(root->right, targetSum - root->val, path);
        }
        path.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }
};