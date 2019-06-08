class Solution {
public:
    bool isPowerOfThree(int n) {
        //version2
        if (n >1)
        {
            while (n % 3 == 0)
                n /= 3;
        }
        return n == 1;

        // version1
        // int i = 0;
        // while(pow(3, i) <= n)
        // {
        //     if (pow(3, i) == n)
        //         return true;
        //     i++;
        // }
        // return false;
    }
};