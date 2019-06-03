class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int res = 0;
        int one_step_before = max(nums[0], nums[1]);
        int two_step_before = nums[0];
        for (int i = 2; i < n; i++)
        {
            res = max(one_step_before, two_step_before + nums[i]);
            two_step_before = one_step_before;
            one_step_before = res;
        }
        return res;
    }
};