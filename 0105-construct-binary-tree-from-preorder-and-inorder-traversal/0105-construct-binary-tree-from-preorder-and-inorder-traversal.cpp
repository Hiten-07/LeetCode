class Solution {
public:
    unordered_map<int,int> idx; // value -> inorder index

    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;

        int rootVal = preorder[ps];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = idx[rootVal];
        int leftSize = inRoot - is;

        root->left = build(preorder, ps+1, ps+leftSize,
                           inorder, is, inRoot-1);
        root->right = build(preorder, ps+leftSize+1, pe,
                            inorder, inRoot+1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) idx[inorder[i]] = i;
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
};