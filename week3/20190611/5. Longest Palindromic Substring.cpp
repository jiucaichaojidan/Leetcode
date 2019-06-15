class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            string tmp = Palindrom(s, i, i);
            if (tmp.size() > res.size())
            {
                res = tmp;
            }
            
            tmp = Palindrom(s, i, i + 1);
            if (tmp.size() > res.size())
            {
                res = tmp;
            }            
        }
        return res;
        
    }
    
    
    
    string Palindrom(string s, int l, int h){        
        while(l >= 0 && h < s.size() && s[l] == s[h])
        {
            l --;
            h ++;
        }
        return s.substr(l + 1, h - l - 1);       
    }
};