class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            if (n & 1) // 和1按位与，实际上在取这个数二进制的最后一位，判断若最后一位为1则res最后一位为1 为0则不变
            {
                res |= 1; /* 原来的数每一位：除了最后一位， 若为0 则为00若为1 则为1  即除最后一位外全部不变 
                             最后一位为1 则为1 */
            }
            n >>= 1;
        
        }
        return res;
    }
};