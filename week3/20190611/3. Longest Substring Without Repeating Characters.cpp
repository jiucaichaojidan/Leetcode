class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0};
        int left = 0;
        int res = 0;
        
        for(int i= 0; i <s.size(); i++)
        {
            if(m[s[i]] == 0)
            {          
                res = max(res, i - left + 1);
            }
            else
            {
                if(m[s[i]] < left)
                    res = max(res, i - left + 1);
                else
                    left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        
        return res;
    }
};