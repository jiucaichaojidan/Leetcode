// 树的最小深度（从根节点到离他最近的叶节点的最短路径的深度）
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
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        int l = minDepth(root -> left);
        int r = minDepth(root -> right);
        
        if(l == 0 || r == 0) 
            return l + r + 1;
        else
            return min(l, r) + 1;
        
    }
};