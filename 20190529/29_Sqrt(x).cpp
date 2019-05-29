class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        if(x == 1)
        {
            return 1;
        }
        while (end - start > 1)
        {
            long mid = (end + start) / 2;
            if (mid * mid > x)
            {
                end = mid;
            }
            else if (mid * mid < x)
            {
                start = mid;
            }
            else 
            {
                return mid;
            }
        }
        return start;
        
    }
};