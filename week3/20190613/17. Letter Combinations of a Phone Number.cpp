// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.size() == 0) return res;
        
        res.push_back("");
        string dic[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tmp;
            for(auto c:dic[digits[i] - '0'])
            { 
                for(auto r : res)
                    tmp.push_back(r + c);
            }
            res = tmp;
        }
        return res;
        
    }
};
