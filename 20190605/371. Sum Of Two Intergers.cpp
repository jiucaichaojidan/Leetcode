class Solution {
public:
    int getSum(int a, int b) {
        int res = a;
        long car; // 进位，避免负数左移出错 类型采用long
        
        while(b != 0)
        {
            res = a ^ b; //不考虑进位的加法，同为1为0， 同为0为0， 一个1一个0为1
            car = a & b;
            b = (car & 0xffffffff) << 1; 
            a = res;
        }
        
        return res;
        
    }
};