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
        if(!root) return true;
        
        return equal(root -> left, root -> right);      
        
        
    }
    
    bool equal(TreeNode* p, TreeNode* q){
        
            if(!p || !q) return (p == q);
        
            if(p -> val != q -> val) return false;
        
            return equal(p -> left, q -> right) && equal(p -> right, q -> left);
        }
};