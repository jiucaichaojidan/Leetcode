// 字符串中最后一个单词
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int l = s.size() - 1;
        
        int len = 0;
        for(int i = 0; i <= l; i++)
        {
            if(s[l - i] == ' ')
                if(len == 0 && i < l) continue;
                else
                    return len;
            else
                len++;
            
        }
        return len;
        
    }
};