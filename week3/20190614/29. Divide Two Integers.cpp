// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

// Return the quotient after dividing dividend by divisor.

// The integer division should truncate toward zero.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long dv = labs(dividend), ds = labs(divisor);
        long res = 0;
        
        while(dv >= ds)
        {
            int i = 0;
            long tmp = ds;
            while(tmp <<1 <= dv)
            {
                i++;
                tmp <<= 1;
            }
            res += (1 << i);
            
            dv -= tmp;
            
        }
      
        return sign * res;

    }
};