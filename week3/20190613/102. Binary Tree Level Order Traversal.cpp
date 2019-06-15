// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]


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
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        vector<int> cur;
        while(!que.empty())
        {
            TreeNode* tmp = que.front();
            que.pop();
            if(tmp == NULL)
            {
                res.push_back(cur);
                cur.resize(0);
                if(que.size() > 0)
                    que.push(NULL);
            }
            else
            {
                cur.push_back(tmp -> val);
                if(tmp -> left) que.push(tmp -> left);
                if(tmp -> right) que.push(tmp -> right);
            }
        }
        return res;
        
        
    }
};