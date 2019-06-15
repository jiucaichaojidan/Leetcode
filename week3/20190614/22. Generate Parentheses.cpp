// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0) return res;
        helper(res, "", n, n);
        return res;
    }
    
    void helper(vector<string> &res, string s, int l, int r)
    {
        if(l > r) return;
        if(l==0 && r == 0) res.push_back(s);
        else
        {
            if(l > 0) helper(res, s + '(', l - 1, r);
            if(r > 0) helper(res, s + ')', l, r - 1);
        }
    }
};