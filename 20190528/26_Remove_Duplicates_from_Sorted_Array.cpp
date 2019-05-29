class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int res = ! nums.empty();
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i-1])
            {
                res += 1;
                               
            }
            else
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        
        return res;
        
    }
};