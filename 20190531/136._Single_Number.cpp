class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 思路：利用异或运算（按位）
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        
        return res;
    }
};