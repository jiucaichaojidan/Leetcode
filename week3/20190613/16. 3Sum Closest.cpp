// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dis = INT_MAX;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(sum - target) < dis)
                {
                    dis = abs(sum - target);
                    res = sum;
                }
                        
                if(sum < target) l++;
                else if(sum > target) r--;
                else return sum;
                         
            }
        }
        return res;
        
    }
};