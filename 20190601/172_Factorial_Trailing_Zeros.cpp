class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int tmp = 0;
        while (n / 5 > 0)
        {
            tmp = n / 5;
            res += tmp;
            n = tmp;
        }
        return res;
             
        
        // if (n == 0) return 0;
        // return n / 5 + trailingZeroes( n / 5);
    }
};