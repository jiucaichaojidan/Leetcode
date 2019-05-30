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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res = helper(nums, 0, nums.size() - 1);
        return res;
    }
    
    TreeNode* helper(vector<int>& nums, int low, int high){
        
        if (low > high) return nullptr;
        
        int mid = (high + low) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = helper(nums, low, mid - 1);
        node ->right = helper(nums, mid + 1, high);
        
        return node;
    }
};