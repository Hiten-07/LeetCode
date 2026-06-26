class Solution {
public:
    unordered_map<int,int> idx; // value -> inorder index
    int postIdx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int is, int ie) {
        if (is > ie) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = idx[rootVal];

        // build right subtree first
        root->right = build(inorder, postorder, inRoot+1, ie);
        root->left  = build(inorder, postorder, is, inRoot-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) idx[inorder[i]] = i;
        postIdx = n-1;
        return build(inorder, postorder, 0, n-1);
    }
};