# include <math.h>
class Solution {
public:
    int titleToNumber(string s) {
        
        int res = 0;
        int l = s.size();
        
        for(int i = 0; i < s.size(); i++)
        {
            res += (int(s[l - i -1]) - int('A') + 1) * pow(26, i);
        }
        
        return res;
    }
};