class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 复杂度O(n)
        for(int i = 0; i < nums.size(); i++)
        {
            if(target <= nums[i])
                return i;
        }
        return nums.size();

        // 复杂度O(logn)
        // int l = 0, h = nums.size() - 1;
        // while(l <= h)
        // {
        //     int mid = (l + h) / 2;
        //     if(nums[mid] == target)
        //         return mid;
        //     if(nums[mid] < target)
        //         l = mid + 1;
        //     else
        //         h = mid - 1;
        // }
        // return l;
        
    }
};