class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = n * (n + 1) / 2;
        for (int num : nums)
            sum -= num;
        return sum;

        // version2
        //         int res = nums.size();
        // int i = 0;
        
        // for(int num:nums)
        // {
        //     res ^= num;
        //     res ^= i;
        //     i ++;
        // }
        
        // return res;
    }
};