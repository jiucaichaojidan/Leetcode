// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        
        for(int i = 0; i < nums.size() - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
                
            for(int j = i + 1; j < nums.size() - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int l = j + 1; 
                int r = nums.size() - 1;
                while(l < r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target) l++;
                    else if(sum > target) r--;
                    else 
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;

                        l++;
                        r--;    
                    }
                }
            }
        }
        return res;
    
    }
};

