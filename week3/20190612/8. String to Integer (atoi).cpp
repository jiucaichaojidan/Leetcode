// Implement atoi which converts a string to an integer.
// Note:
// Only the space character ' ' is considered as whitespace character.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

// Input: "   -42"
// Output: -42
// Input: "4193 with words"
// Output: 4193
// Input: "words and 987"
// Output: 0
// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.

class Solution {
public:
    int myAtoi(string str) {
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] != ' ')
            {
                if(isdigit(str[i]))
                    return toInterger(1, str, i);
                else if (str[i] == '-' || str[i] == '+')
                {
                    if (isdigit(str[i + 1]))
                        return toInterger(str[i] == '-' ? -1 : 1, str, i + 1);
                    else
                        return 0;
                }
                else
                    return 0;
            }
           
        }
        return 0;
    }
    
    int toInterger(int sign, string str, int i)
    {
        long res = 0;
        while (isdigit(str[i]))
        {
            res = res * 10 + str[i] - '0';
            if(sign == 1 && res > INT_MAX)
                return INT_MAX;
            if(sign == - 1 && sign * res < INT_MIN)
                return INT_MIN;
            i++;
        }
        
        return (int) (res * sign);
    }
};