class Solution {
public:
    string countAndSay(int n) {
        
        string res = "1";
        
        for (int i = 1; i < n; i++)
        {            
            string temp;
            
            for (int j = 0; j < res.length(); j++)
            {                
                int cnt = 1;                
                while(j < res.length() - 1 && res[j] == res[j + 1])
                {
                    cnt += 1;
                    j ++;
                }
                temp += to_string(cnt) + res[j];
            }
            
            res = temp;
        }
        return res;
    }
};