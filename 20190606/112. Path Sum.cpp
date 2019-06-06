// 判断是否存在一条路径，从根节点到叶结点的和为给定的值
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root -> val == sum && root->left==NULL && root->right==NULL) // !!!
            return true;
        return hasPathSum(root -> left, sum - root->val)||
               hasPathSum(root -> right, sum - root->val);
    }
};