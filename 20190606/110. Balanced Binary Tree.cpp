// 判断二叉树是否平衡（每个结点任意两个子树的高度差不大于一）
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = depth(root -> left);
        int r = depth(root -> right);
        if(abs(l - r) > 1)
            return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
        
    }
    
    int depth(TreeNode* p)
    {
        if(!p) return 0;
        return max(depth(p -> left), depth(p -> right)) + 1;
    }
};