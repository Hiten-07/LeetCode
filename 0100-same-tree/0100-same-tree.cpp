class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;          // both null
        if (!p || !q) return false;         // one null, one not
        if (p->val != q->val) return false; // values differ
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
