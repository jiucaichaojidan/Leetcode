/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return rec(root ->left, root -> right);
    }
    
    bool rec(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 || !t2)
        {
            if (!t1 && !t2) return true;
            // if (!(t1 && t2)) return false;
            return false;
        }
        if (t1 -> val != t2 -> val) return false;
        return rec(t1 -> left, t2 -> right) && rec(t1 -> right, t2 -> left);
    }
};